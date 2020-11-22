#include "dsk_core.h"

bool dskCreateWindow(DskWindow *window, const DskWindowSettings *settings)
{
       atk_api_assert(window != NULL && settings != NULL);
       glfwDefaultWindowHints();
       glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
       glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
       glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
       GLFWmonitor *monitor = glfwGetPrimaryMonitor();
       atk_api_assert(monitor != NULL);
       GLFWwindow *glfw_window = glfwCreateWindow(settings->width, settings->height, settings->title, settings->fullscreen ? monitor : NULL, NULL);
       if (window == NULL)
       {
              atk_api_dbg_error("failed to create window");
              return false;
       }
       window->m_handle = glfw_window;
       window->m_width = settings->width;
       window->m_height = settings->height;
       if (!settings->fullscreen)
       {
              const GLFWvidmode *vidmode = glfwGetVideoMode(monitor);
              atk_api_assert(vidmode != NULL);
              int center_x = (vidmode->width - settings->width) / 2;
              int center_y = (vidmode->height - settings->height) / 2;
              glfwSetWindowPos(glfw_window, center_x, center_y);
       }
       atk_api_dbg_info("window created");
       return true;
}

void dskDestroyWindow(DskWindow *window)
{
       glfwDestroyWindow((GLFWwindow *)window->m_handle);
       window->m_handle = NULL;
       /*window->m_width = 0;
       window->m_height = 0;*/
       atk_api_dbg_info("window destroyed");
}

bool dskWindowShouldClose(DskWindow *window)
{
       atk_api_assert(window != NULL && window->m_handle != NULL);
       return glfwWindowShouldClose((GLFWwindow *)window->m_handle) == GLFW_TRUE;
}

void dskWindowHide(DskWindow *window)
{
       atk_api_assert(window != NULL && window->m_handle != NULL);
       glfwHideWindow((GLFWwindow *)window->m_handle);
}

void dskWindowShow(DskWindow *window)
{
       atk_api_assert(window != NULL && window->m_handle != NULL);
       glfwShowWindow((GLFWwindow *)window->m_handle);
}

#ifdef ATK_PLATFORM_LINUX
Window dskWindowGetX11Window(DskWindow *window)
{
       atk_api_assert(window != NULL && window->m_handle != NULL);
       return glfwGetX11Window((GLFWwindow *)window->m_handle);
}
#endif //ATK_PLATFORM_LINUX