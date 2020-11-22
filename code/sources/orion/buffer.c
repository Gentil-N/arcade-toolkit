#include "orn_core.h"

OrnBuffer *ornCreateBuffer(OrnDevice *device, const OrnBufferSettings *buffer_settings)
{
       OrnBuffer *buffer = (OrnBuffer *)atk_alloc(sizeof(struct OrnBuffer));
       atk_api_assert(buffer != NULL);

       VkBufferCreateInfo buffer_info = vkfBufferCreateInfo(buffer_settings->size, buffer_settings->usage, VK_SHARING_MODE_EXCLUSIVE, 0, NULL);
       orn_assert_vk(device->tbl.vkCreateBuffer(device->handle, &buffer_info, VK_AC, &buffer->handle));

       OrnMemoryAllocationSettings settings;
       settings.buffer = buffer->handle;
       settings.memoryProperties = buffer_settings->memory;
       settings.objectType = ORN_BUFFER_OBJECT_TYPE;
       buffer->alloc = ornAllocateMemory(device->handle, device->memory_allocator, &settings);

       atk_api_dbg_info("buffer created");
       return buffer;
}

void ornDestroyBuffer(OrnDevice *device, OrnBuffer *buffer)
{
       ornFreeMemory(buffer->alloc);
       device->tbl.vkDestroyBuffer(device->handle, buffer->handle, VK_AC);
       atk_free(buffer);
       atk_api_dbg_info("buffer destroyed");
}

void *ornMapBuffer(OrnDevice *device, OrnBuffer *buffer)
{
       return ornMapMemory(device->handle, device->memory_allocator, buffer->alloc);
}

void ornUnmapBuffer(OrnDevice *device, OrnBuffer *buffer)
{
       ornUnmapMemory(device->handle, device->memory_allocator, buffer->alloc);
}