#include "orn_core.h"

OrnSurface *ornCreateSurface(const OrnSurfaceSettings *settings)
{
       OrnSurface *surface = (OrnSurface*)atk_alloc(sizeof(struct OrnSurface));
       atk_assert(surface != NULL);

#ifdef ATK_PLATFORM_LINUX
       VkXlibSurfaceCreateInfoKHR surface_info;
       surface_info.sType = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
       surface_info.pNext = NULL;
       surface_info.flags = 0;
       surface_info.dpy = settings->display;
       surface_info.window = settings->window;
       PFN_vkCreateXlibSurfaceKHR vkCreateSurface = (PFN_vkCreateXlibSurfaceKHR)CONTEXT.mtbl.vkGetInstanceProcAddr(CONTEXT.instance, "vkCreateXlibSurfaceKHR");
       orn_check_ret(vkCreateSurface == NULL, ATK_MSG_FEATURE_NOT_PRESENT, "fonction <vkCreateXlibSurfaceKHR> is not present", NULL);
       orn_assert_vk(vkCreateSurface(CONTEXT.instance, &surface_info, VK_AC, &surface->handle));
#endif //ATK_PLATFORM_LINUX

       atk_info("surface created");
       return surface;
}
void ornDestroySurface(OrnSurface *surface)
{
       CONTEXT.itbl.vkDestroySurfaceKHR(CONTEXT.instance, surface->handle, VK_AC);
       atk_free(surface);
       atk_info("surface destroyed");
}