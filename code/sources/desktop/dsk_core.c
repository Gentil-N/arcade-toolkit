#include "dsk_core.h"

#ifdef ATK_DEBUG
void glfwErrorCallback(int code, const char *description)
{
       atk_verror(ATK_MSG_LIB_REPORT, "%s%i%s%s%s", "glfw error (", code, ") - ", description, " - ");
}
#endif //ATK_DEBUG

bool dskInit()
{
#ifdef ATK_DEBUG
       glfwSetErrorCallback(glfwErrorCallback);
#endif //ATK_DEBUG
       int result = glfwInit();
       if (result != GLFW_TRUE)
       {
              atk_error(ATK_MSG_INIT_FAILED, "failed to initialize GLFW");
              return false;
       }
       atk_info("desktop module initialized");
       return true;
}

void dskEnd()
{
       glfwTerminate();
       atk_info("desktop module ended");
}

void dskRefresh()
{
       glfwPollEvents();
}

#ifdef ATK_PLATFORM_LINUX
Display *dskGetX11Display()
{
       return glfwGetX11Display();
}
#endif //ATK_PLATFORM_LINUX