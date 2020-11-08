#ifndef __DSK_CORE_H__
#define __DSK_CORE_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#include "../../include/atk_desktop.h"

#include <GLFW/glfw3.h>
#ifdef ATK_PLATFORM_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#endif //ATK_PLATFORM_LINUX
#include <GLFW/glfw3native.h>

#define DSK_MAX_JOYSTICKS 16

       ATK_GLOBAL AtkVector KEYBOARDS;
       ATK_GLOBAL AtkVector MOUSES;
       ATK_GLOBAL AtkArray JOYSTICKS;

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__DSK_CORE_H__