#include "dsk_core.h"

void keyCallback(GLFWwindow *handle, int key, int scancode, int action, int mods)
{
       for(size_t i = 0; i < KEYBOARDS.m_count; ++i)
       {
              DskKeyboard *curr_keyboard = atk_get(DskKeyboard*, KEYBOARDS, i);
              if(curr_keyboard->m_window->m_handle == handle)
              {
                     if(action == GLFW_PRESS)
                     {
                            curr_keyboard->m_keys_states[key] = GLFW_PRESS;
                            return;
                     }
                     else if(action == GLFW_RELEASE)
                     {
                            curr_keyboard->m_keys_states[key] = GLFW_RELEASE;
                            atkVectorPushBack(&curr_keyboard->m_keys_released, &key);
                            return;
                     }
                     else
                     {
                            return;
                     }
                     
              }
       }
       atk_warn(ATK_MSG_RESOURCE_MISSING, "failed to find window handle (key callback)");
}

void dskCreateKeyboard(DskKeyboard *keyboard, const DskKeyboardSettings *settings)
{
       keyboard->m_window = settings->window;
       memset(keyboard->m_keys_states, DSK_STATE_NOP, DSK_MAX_KEYS * sizeof(int));
       atkNewVector(&keyboard->m_keys_released, 0, sizeof(int));
       glfwSetKeyCallback(settings->window->m_handle, keyCallback);
       atkVectorPushBack(&KEYBOARDS, &keyboard);
}

void dskDestroyKeyboard(DskKeyboard *keyboard)
{
       for(size_t i = 0; i < KEYBOARDS.m_count; ++i)
       {
              if(atk_get(DskKeyboard*, KEYBOARDS, i) == keyboard)
              {
                     atkVectorRemove(&KEYBOARDS, i);
                     break;
              }
       }
       atkDeleteVector(&keyboard->m_keys_released);
       keyboard->m_window = NULL;
}

bool dskKeyboardIsKeyPressed(DskKeyboard *keyboard, DskKey key)
{
       return keyboard->m_keys_states[(int)key] == GLFW_PRESS;
}

bool dskKeyboardIsKeyReleased(DskKeyboard *keyboard, DskKey key)
{
       return keyboard->m_keys_states[(int)key] == GLFW_RELEASE;
}