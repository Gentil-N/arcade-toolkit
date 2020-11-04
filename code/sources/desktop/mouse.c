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
                            curr_mouse->m_buttons_states[button] = GLFW_PRESS;
                            return;
                     }
                     else if(action == GLFW_RELEASE)
                     {
                            curr_mouse->m_buttons_states[button] = GLFW_RELEASE;
                            atkVectorPushBack(&curr_mouse->m_buttons_released, &button);
                            return;
                     }
              }
       }
       atk_warn(ATK_MSG_RESOURCE_MISSING, "failed to find window handle (button callback)");
}

void dskCreateMouse(DskMouse *mouse, const DskMouseSettings *settings)
{
       mouse->m_window = settings->window;
       memset(mouse->m_buttons_states, DSK_STATE_NOP, DSK_MAX_MOUSE_BUTTONS * sizeof(int));
       atkNewVector(&mouse->m_buttons_released, 0, sizeof(int));
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
       atkDeleteVector(&mouse->m_buttons_released);
       mouse->m_window = NULL;
}

bool dskMouseIsMouseButtonPressed(DskMouse *mouse, DskMouseButton button)
{
       return mouse->m_buttons_states[(int)button] == GLFW_PRESS;
}

bool dskMouseIsMouseButtonReleased(DskMouse *mouse, DskMouseButton button)
{
       return mouse->m_buttons_states[(int)button] == GLFW_RELEASE;
}

AtkPack2d dskMouseGetCursorPos(DskMouse *mouse)
{
       AtkPack2d pos = {0};
       glfwGetCursorPos(mouse->m_window->m_handle, &pos.x, &pos.y);
       return pos;
}