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
                            atkVectorPushBack(&curr_keyboard->m_key_pressed, &key);
                            return;
                     }
                     else if(action == GLFW_RELEASE)
                     {
                            atkVectorPushBack(&curr_keyboard->m_key_released, &key);
                            for(size_t i = 0; i < curr_keyboard->m_key_pressed.m_count; ++i)
                            {
                                   if(atk_get(int, curr_keyboard->m_key_pressed, i) == key)
                                   {
                                          atkVectorRemove(&curr_keyboard->m_key_pressed, i);
                                          return;
                                   }
                            }
                            atk_warn(ATK_MSG_RESOURCE_MISSING, "failed to find key (key callback)");
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
       atkNewVector(&keyboard->m_key_pressed, 0, sizeof(int));
       atkNewVector(&keyboard->m_key_released, 0, sizeof(int));
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
       atkDeleteVector(&keyboard->m_key_released);
       atkDeleteVector(&keyboard->m_key_pressed);
}

bool dskKeyboardIsKeyPressed(DskKeyboard *keyboard, int key)
{
       for(size_t i = 0; i < keyboard->m_key_pressed.m_count; ++i)
       {
              if(atk_get(int, keyboard->m_key_pressed, i) == key)
              {
                     return true;
              }
       }
       return false;
}

bool dskKeyboardIsKeyReleased(DskKeyboard *keyboard, int key)
{
       for(size_t i = 0; i < keyboard->m_key_released.m_count; ++i)
       {
              if(atk_get(int, keyboard->m_key_released, i) == key)
              {
                     return true;
              }
       }
       return false;
}