#include "dsk_core.h"

void mouseButtonCallback(GLFWwindow *handle, int button, int action, int mods)
{
       for(size_t i = 0; i < MOUSES.m_count; ++i)
       {
              DskMouse *curr_mouse = atk_get(DskMouse*, MOUSES, i);
              if(curr_mouse->m_window->m_handle == handle)
              {
                     if(action == GLFW_PRESS)
                     {
                            atkVectorPushBack(&curr_mouse->m_button_pressed, &button);
                            return;
                     }
                     else if(action == GLFW_RELEASE)
                     {
                            atkVectorPushBack(&curr_mouse->m_button_released, &button);
                            for(size_t i = 0; i < curr_mouse->m_button_pressed.m_count; ++i)
                            {
                                   if(atk_get(int, curr_mouse->m_button_pressed, i) == button)
                                   {
                                          atkVectorRemove(&curr_mouse->m_button_pressed, i);
                                          return;
                                   }
                            }
                            atk_warn(ATK_MSG_RESOURCE_MISSING, "failed to find button (button callback)");
                     }
              }
       }
       atk_warn(ATK_MSG_RESOURCE_MISSING, "failed to find window handle (button callback)");
}

void dskCreateMouse(DskMouse *mouse, const DskMouseSettings *settings)
{
       mouse->m_window = settings->window;
       atkNewVector(&mouse->m_button_pressed, 0, sizeof(int));
       atkNewVector(&mouse->m_button_released, 0, sizeof(int));
       glfwSetMouseButtonCallback(settings->window->m_handle, mouseButtonCallback);
       atkVectorPushBack(&MOUSES, &mouse);
}

void dskDestroyMouse(DskMouse *mouse)
{
       for(size_t i = 0; i < MOUSES.m_count; ++i)
       {
              if(atk_get(DskMouse*, MOUSES, i) == mouse)
              {
                     atkVectorRemove(&MOUSES, i);
                     break;
              }
       }
       atkDeleteVector(&mouse->m_button_released);
       atkDeleteVector(&mouse->m_button_pressed);
}

bool dskMouseIsMouseButtonPressed(DskMouse *mouse, int button)
{
       for(size_t i = 0; i < mouse->m_button_pressed.m_count; ++i)
       {
              if(atk_get(int, mouse->m_button_pressed, i) == button)
              {
                     return true;
              }
       }
       return false;
}

bool dskMouseIsMouseButtonReleased(DskMouse *mouse, int button)
{
       for(size_t i = 0; i < mouse->m_button_released.m_count; ++i)
       {
              if(atk_get(int, mouse->m_button_released, i) == button)
              {
                     return true;
              }
       }
       return false;
}

AtkPack2d dskMouseGetCursorPos(DskMouse *mouse)
{
       AtkPack2d pos = {0};
       glfwGetCursorPos(mouse->m_window->m_handle, &pos.x, &pos.y);
       return pos;
}