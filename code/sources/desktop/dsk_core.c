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
       atkNewVector(&KEYBOARDS, 0, sizeof(DskKeyboard *));
       atkNewVector(&MOUSES, 0, sizeof(DskMouse *));
       atk_info("desktop module initialized");
       return true;
}

void dskEnd()
{
       atkDeleteVector(&MOUSES);
       atkDeleteVector(&KEYBOARDS);
       glfwTerminate();
       atk_info("desktop module ended");
}

void dskRefresh()
{
       for(size_t i = 0; i < KEYBOARDS.m_count; ++i)
       {
              atk_get(DskKeyboard*, KEYBOARDS, i)->m_key_released.m_count = 0;//the size will not exceed the number of keys
       }
       for(size_t i = 0; i < MOUSES.m_count; ++i)
       {
              atk_get(DskMouse*, MOUSES, i)->m_button_released.m_count = 0;//the size will not exceed the number of buttons
       }
       glfwPollEvents();
}

#ifdef ATK_PLATFORM_LINUX
Display *dskGetX11Display()
{
       return glfwGetX11Display();
}
#endif //ATK_PLATFORM_LINUX