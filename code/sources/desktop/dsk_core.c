#include "dsk_core.h"

#ifdef ATK_DEBUG
void glfwErrorCallback(int code, const char *description)
{
       atk_api_dbg_error("%s%i%s%s%s", "glfw error (", code, ") - ", description, " - ");
}
#endif //ATK_DEBUG

void joystickCallback(int id, int event)
{
       atk_api_assert(0 <= id <= DSK_MAX_JOYSTICKS);
       switch(event)
       {
              case GLFW_CONNECTED :
              {
                     atk_get(DskJoystick *, JOYSTICKS, id)->m_connected = true;
                     return;
              }
              case GLFW_DISCONNECTED :
              {
                     atk_get(DskJoystick *, JOYSTICKS, id)->m_connected = false;
                     return;
              }
              default :
              {
                     atk_api_dbg_warn("joystick event unknow");
              }
       }
}

bool dskInit()
{
#ifdef ATK_DEBUG
       glfwSetErrorCallback(glfwErrorCallback);
#endif //ATK_DEBUG
       int result = glfwInit();
       if (result != GLFW_TRUE)
       {
              atk_api_dbg_error("failed to initialize GLFW");
              return false;
       }
       atkNewVector(&KEYBOARDS, 0, sizeof(DskKeyboard *));
       atkNewVector(&MOUSES, 0, sizeof(DskMouse *));
       atkNewArray(&JOYSTICKS, DSK_MAX_JOYSTICKS, sizeof(DskJoystick *));
       for(size_t i = 0; i < JOYSTICKS.m_count; ++i)
       {
              atk_get(DskJoystick *, JOYSTICKS, i) = (DskJoystick*)atk_alloc(sizeof(struct DskJoystick));
              DskJoystick *curr_joy = atk_get(DskJoystick *, JOYSTICKS, i);
              curr_joy->m_connected = glfwJoystickPresent(i) == GLFW_TRUE;
              *(int*)&curr_joy->m_id = i;
       }
       glfwSetJoystickCallback(joystickCallback);
       atk_api_dbg_info("desktop module initialized");
       return true;
}

void dskEnd()
{
       for(size_t i = 0; i < JOYSTICKS.m_count; ++i)
       {
              atk_free(atk_get(DskJoystick *, JOYSTICKS, i));
       }
       atkDeleteArray(&JOYSTICKS);
       atkDeleteVector(&MOUSES);
       atkDeleteVector(&KEYBOARDS);
       glfwTerminate();
       atk_api_dbg_info("desktop module ended");
}

void dskRefresh()
{
       for (size_t i = 0; i < KEYBOARDS.m_count; ++i)
       {
              DskKeyboard *keyboard = atk_get(DskKeyboard *, KEYBOARDS, i);
              for (size_t j = 0; j < keyboard->m_keys_released.m_count; ++j)
              {
                     keyboard->m_keys_states[atk_get(int, keyboard->m_keys_released, j)] = DSK_STATE_NOP;
              }
              keyboard->m_keys_released.m_count = 0; //the size will not exceed the number of keys
       }
       for (size_t i = 0; i < MOUSES.m_count; ++i)
       {
              DskMouse *mouse = atk_get(DskMouse *, MOUSES, i);
              for (size_t j = 0; j < mouse->m_buttons_released.m_count; ++j)
              {
                     mouse->m_buttons_states[atk_get(int, mouse->m_buttons_released, j)] = DSK_STATE_NOP;
              }
              mouse->m_buttons_released.m_count = 0; //the size will not exceed the number of buttons
       }
       glfwPollEvents();
}

#ifdef ATK_PLATFORM_LINUX
Display *dskGetX11Display()
{
       return glfwGetX11Display();
}
#endif //ATK_PLATFORM_LINUX