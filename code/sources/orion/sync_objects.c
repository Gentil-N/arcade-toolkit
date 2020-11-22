#include "orn_core.h"

OrnSyncObjects *ornCreateSyncObjects(const VklDeviceTable *dtbl, VkDevice device, uint32_t count)
{
       OrnSyncObjects *sync_objects = (OrnSyncObjects*)atk_alloc(sizeof(struct OrnSyncObjects));
       atk_api_assert(sync_objects != NULL);

       VkSemaphoreCreateInfo semaphore_info = vkfSemaphoreCreateInfo();
       VkFenceCreateInfo fence_info = vkfFenceCreateInfo();
       atkNewArray(&sync_objects->image_available_sems, count, sizeof(VkSemaphore));
       atkNewArray(&sync_objects->render_complete_sems, count, sizeof(VkSemaphore));
       atkNewArray(&sync_objects->fences, count, sizeof(VkFence));
       fence_info.flags = VK_FENCE_CREATE_SIGNALED_BIT;
       for (uint32_t i = 0; i < count; ++i)
       {
              orn_assert_vk(dtbl->vkCreateSemaphore(device, &semaphore_info, VK_AC, &atk_get(VkSemaphore, sync_objects->image_available_sems, i)));
              orn_assert_vk(dtbl->vkCreateSemaphore(device, &semaphore_info, VK_AC, &atk_get(VkSemaphore, sync_objects->render_complete_sems, i)));
              orn_assert_vk(dtbl->vkCreateFence(device, &fence_info, VK_AC, &atk_get(VkFence, sync_objects->fences, i)));
       }
       atk_api_dbg_info("sync objects created");
       return sync_objects;
}

void ornDestroySyncObjects(const VklDeviceTable *dtbl, VkDevice device, OrnSyncObjects *sync_objects)
{
       for (size_t i = 0; i < sync_objects->image_available_sems.m_count; ++i)
       {
              dtbl->vkDestroyFence(device, atk_get(VkFence, sync_objects->fences, i), VK_AC);
              dtbl->vkDestroySemaphore(device, atk_get(VkSemaphore, sync_objects->render_complete_sems, i), VK_AC);
              dtbl->vkDestroySemaphore(device, atk_get(VkSemaphore, sync_objects->image_available_sems, i), VK_AC);
       }
       atkDeleteArray(&sync_objects->fences);
       atkDeleteArray(&sync_objects->render_complete_sems);
       atkDeleteArray(&sync_objects->image_available_sems);
       atk_free(sync_objects);
       atk_api_dbg_info("sync objects destroyed");
}