#include "orn_core.h"

const uint32_t DEV_EXTENSIONS_COUNT = 1;
const char *DEV_EXTENSIONS[1] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};

OrnDevice *ornCreateDevice(const OrnDeviceSettings *settings)
{
       OrnDevice *device = (OrnDevice *)atk_alloc(sizeof(struct OrnDevice));
       atk_assert(device != NULL);

       device->gpu = settings->gpu;

       VkDeviceQueueCreateInfo queue_infos[2];
       VkPhysicalDeviceFeatures features = {0};
       features.samplerAnisotropy = settings->enable_anisotropy;
       VkDeviceCreateInfo device_info = vkfDeviceCreateInfo(1, queue_infos, 0, NULL, DEV_EXTENSIONS_COUNT, DEV_EXTENSIONS, &features);
       float priority = 1.0f;
       if (settings->gpu->graphics_queue_index == settings->gpu->present_queue_index)
       {
              queue_infos[0] = vkfDeviceQueueCreateInfo(settings->gpu->graphics_queue_index, 1, &priority);
       }
       else
       {
              queue_infos[0] = vkfDeviceQueueCreateInfo(settings->gpu->graphics_queue_index, 1, &priority);
              queue_infos[1] = vkfDeviceQueueCreateInfo(settings->gpu->present_queue_index, 1, &priority);
              device_info.queueCreateInfoCount = 2;
       }
       orn_assert_vk(CONTEXT.itbl.vkCreateDevice(settings->gpu->handle, &device_info, VK_AC, &device->handle));

       vklLoadDeviceTable(device->handle, &CONTEXT.itbl, &device->tbl);
       device->tbl.vkGetDeviceQueue(device->handle, settings->gpu->graphics_queue_index, 0, &device->graphics_queue);
       device->tbl.vkGetDeviceQueue(device->handle, settings->gpu->present_queue_index, 0, &device->present_queue);

       VkCommandPoolCreateInfo command_pool_info = vkfCommandPoolCreateInfo(settings->gpu->graphics_queue_index);
       command_pool_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
       orn_assert_vk(device->tbl.vkCreateCommandPool(device->handle, &command_pool_info, VK_AC, &device->command_pool));

       VkmAllocatorCreateInfo allocator_info;
       allocator_info.allocationCallbacks = VK_AC;
       allocator_info.memoryPoolSize = ORN_MEMORY_POOL_SIZE;
       allocator_info.pfn_allocateMemory = device->tbl.vkAllocateMemory;
       allocator_info.pfn_bindBufferMemory = device->tbl.vkBindBufferMemory;
       allocator_info.pfn_bindImageMemory = device->tbl.vkBindImageMemory;
       allocator_info.pfn_freeMemory = device->tbl.vkFreeMemory;
       allocator_info.pfn_getBufferMemoryRequirements = device->tbl.vkGetBufferMemoryRequirements;
       allocator_info.pfn_getImageMemoryRequirements = device->tbl.vkGetImageMemoryRequirements;
       allocator_info.pfn_getPhysicalDeviceMemoryProperties = CONTEXT.itbl.vkGetPhysicalDeviceMemoryProperties;
       allocator_info.pfn_mapMemory = device->tbl.vkMapMemory;
       allocator_info.pfn_unmapMemory = device->tbl.vkUnmapMemory;
       allocator_info.physicalDevice = settings->gpu->handle;
       vkmCreateAllocator(&allocator_info, &device->allocator);

       device->swapchain = ornCreateSwapchain(device->handle, &device->tbl, settings->gpu, settings->width, settings->height, settings->surface);
       device->sync_objects = ornCreateSyncObjects(&device->tbl, device->handle, (uint32_t)device->swapchain->images.m_count);
       device->curr_image_id = -1;
       atkNewVector(&device->commands, 0, sizeof(OrnCommand *));
       atkNewArray(&device->command_buffers_per_frame, device->swapchain->images.m_count, sizeof(AtkVector));
       for (size_t i = 0; i < device->command_buffers_per_frame.m_count; ++i)
       {
              atkNewVector(&atk_get(AtkVector, device->command_buffers_per_frame, i), 0, sizeof(VkCommandBuffer));
       }
       atkNewVector(&device->msgs, 0, sizeof(struct OrnDeviceMsg));

       atk_info("device created");
       return device;
}

void ornDestroyDevice(OrnDevice *device)
{
       ornParseDeviceMsgs(device, true);
       atkDeleteVector(&device->msgs);

       for (size_t i = 0; i < device->command_buffers_per_frame.m_count; ++i)
       {
              atkDeleteVector(&atk_get(AtkVector, device->command_buffers_per_frame, i));
       }
       atkDeleteArray(&device->command_buffers_per_frame);
       atkDeleteVector(&device->commands);

       ornDestroySyncObjects(&device->tbl, device->handle, device->sync_objects);
       ornDestroySwapchain(device->handle, &device->tbl, device->swapchain);

       vkmDestroyAllocator(device->handle, device->allocator);
       device->tbl.vkDestroyCommandPool(device->handle, device->command_pool, VK_AC);
       device->tbl.vkDestroyDevice(device->handle, VK_AC);
       atk_free(device);
       atk_info("device destroyed");
}

void ornPushDeviceMsg(OrnDevice *device, OrnDeviceMsgType type, void *data)
{
       OrnDeviceMsg msg = {type, data};
       atkVectorPushBack(&device->msgs, &msg);
}

void executeDeviceMsg(OrnDevice *device, OrnDeviceMsg *msg)
{
       switch (msg->type)
       {
       default:
       {
              atk_error(ATK_MSG_INVALID_ARGUMENT, "failed to execute a device message");
       }
       break;
       }
       atkFree(msg->data);
}

void ornParseDeviceMsgs(OrnDevice *device, bool force_wait)
{
       if (device->msgs.m_count == 0 && !force_wait)
       {
              return;
       }
       device->tbl.vkDeviceWaitIdle(device->handle);
       device->tbl.vkQueueWaitIdle(device->graphics_queue);
       for (size_t i = 0; i < device->msgs.m_count; ++i)
       {
              executeDeviceMsg(device, &atk_get(OrnDeviceMsg, device->msgs, i));
       }
       atkVectorClear(&device->msgs);
}

void ornUpdateDevice(OrnDevice *device, bool force_wait)
{
       ornParseDeviceMsgs(device, force_wait);
}

void ornRenderNextFrame(OrnDevice *device)
{
       uint32_t next_index = (device->curr_image_id + 1) % (uint32_t)(device->swapchain->images.m_count);

       orn_assert_vk(device->tbl.vkWaitForFences(device->handle, 1, &atk_get(VkFence, device->sync_objects->fences, next_index), VK_TRUE, UINT64_MAX));
       orn_assert_vk(device->tbl.vkResetFences(device->handle, 1, &atk_get(VkFence, device->sync_objects->fences, next_index)));

       orn_assert_vk(device->tbl.vkAcquireNextImageKHR(
           device->handle, device->swapchain->handle, UINT64_MAX, atk_get(VkSemaphore, device->sync_objects->image_available_sems, next_index),
           VK_NULL_HANDLE, &device->curr_image_id));

       VkPipelineStageFlags wait_dst_stage[1] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
       AtkVector *commands = &atk_get(AtkVector, device->command_buffers_per_frame, device->curr_image_id);
       VkSubmitInfo submit_info = vkfSubmitInfo(
           1, &atk_get(VkSemaphore, device->sync_objects->image_available_sems, device->curr_image_id),
           wait_dst_stage,
           (uint32_t)commands->m_count, (VkCommandBuffer *)commands->m_data,
           1, &atk_get(VkSemaphore, device->sync_objects->render_complete_sems, device->curr_image_id));
       orn_assert_vk(device->tbl.vkQueueSubmit(device->graphics_queue, 1, &submit_info, atk_get(VkFence, device->sync_objects->fences, device->curr_image_id)));

       VkPresentInfoKHR present_info = vkfPresentInfoKHR(
           1, &atk_get(VkSemaphore, device->sync_objects->render_complete_sems, device->curr_image_id), 1, &device->swapchain->handle, &device->curr_image_id, NULL);
       orn_assert_vk(device->tbl.vkQueuePresentKHR(device->present_queue, &present_info));
}