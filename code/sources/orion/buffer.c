#include "orn_core.h"

OrnBuffer *ornCreateBuffer(OrnDevice *device, const OrnBufferSettings *buffer_settings)
{
       OrnBuffer *buffer = (OrnBuffer *)atk_alloc(sizeof(struct OrnBuffer));
       atk_assert(buffer != NULL);

       VkBufferCreateInfo buffer_info = vkfBufferCreateInfo(buffer_settings->size, buffer_settings->usage, VK_SHARING_MODE_EXCLUSIVE, 0, NULL);
       orn_assert_vk(device->tbl.vkCreateBuffer(device->handle, &buffer_info, VK_AC, &buffer->handle));

       VkmAllocationCreateInfo allocation_info;
       allocation_info.buffer = buffer->handle;
       allocation_info.memoryProperties = buffer_settings->memory;
       allocation_info.objectType = VKM_BUFFER_OBJECT_TYPE;
       orn_assert_vk(vkmAllocateMemory(device->handle, device->allocator, &allocation_info, &buffer->allocation));

       atk_info("buffer created");
       return buffer;
}

void ornDestroyBuffer(OrnDevice *device, OrnBuffer *buffer)
{
       vkmFreeMemory(device->allocator, buffer->allocation);
       device->tbl.vkDestroyBuffer(device->handle, buffer->handle, VK_AC);
       atk_free(buffer);
       atk_info("buffer destroyed");
}

void *ornMapBuffer(OrnDevice *device, OrnBuffer *buffer)
{
       void *data = NULL;
       orn_assert_vk(vkmMapMemory(device->handle, device->allocator, buffer->allocation, &data));
       return data;
}

void ornUnmapBuffer(OrnDevice *device, OrnBuffer *buffer)
{
       vkmUnmapMemory(device->handle, device->allocator, buffer->allocation);
}