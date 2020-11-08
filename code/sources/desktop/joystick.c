#include "dsk_core.h"

DskJoystick *const *dskEnumJoysticks(int *count)
{
       *count = DSK_MAX_JOYSTICKS;
       return (DskJoystick *const *)JOYSTICKS.m_data;
}

const char *dskJoystickGetName(DskJoystick *joystick)
{
       return glfwGetJoystickName(joystick->m_id);
}

void dskJoystickUpdate(DskJoystick *joystick)
{
       joystick->m_buttons = glfwGetJoystickButtons(joystick->m_id, &joystick->m_button_count);
       joystick->m_axes = glfwGetJoystickAxes(joystick->m_id, &joystick->m_axe_count);
       joystick->m_hats = glfwGetJoystickHats(joystick->m_id, &joystick->m_hat_count);
}

float dskJoystickGetAxeState(DskJoystick *joystick, int axe)
{
       atk_assert(0 <= axe <= joystick->m_axe_count);
       return joystick->m_axes[axe];
}

bool dskJoystickIsButtonPressed(DskJoystick *joystick, int button)
{
       atk_assert(0 <= button <= joystick->m_button_count);
       return joystick->m_buttons[button] == GLFW_PRESS;
}

DskJoystickHatState dskJoystickGetHatState(DskJoystick *joystick, int hat)
{
       atk_assert(0 <= hat <= joystick->m_hat_count);
       return (DskJoystickHatState)joystick->m_hats[hat];
}