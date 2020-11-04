#ifndef __DESKTOP_H__
#define __DESKTOP_H__

#ifndef __ATK_H__
#include "atk.h"
#endif //__ATK_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#ifdef ATK_PLATFORM_LINUX
#include <X11/Xlib.h>
#endif //ATK_PLATFORM_LINUX

       ATK_API bool dskInit();
       ATK_API void dskEnd();
       ATK_API void dskRefresh();
#ifdef ATK_PLATFORM_LINUX
       ATK_API Display *dskGetX11Display();
#endif //ATK_PLATFORM_LINUX

       typedef struct DskWindow DskWindow;

       typedef struct DskWindowSettings
       {
              int width, height;
              const char *title;
              bool fullscreen;
       } DskWindowSettings;

       ATK_API bool dskCreateWindow(DskWindow *window, const DskWindowSettings *settings);
       ATK_API void dskDestroyWindow(DskWindow *window);
       ATK_API bool dskWindowShouldClose(DskWindow *window);
       ATK_API void dskWindowHide(DskWindow *window);
       ATK_API void dskWindowShow(DskWindow *window);
#ifdef ATK_PLATFORM_LINUX
       ATK_API Window dskWindowGetX11Window(DskWindow *window);
#endif //ATK_PLATFORM_LINUX

       typedef enum DskKey
       {
              DSK_KEY_SPACE = 32,
              DSK_KEY_APOSTROPHE = 39,
              DSK_KEY_COMMA = 44,
              DSK_KEY_MINUS = 45,
              DSK_KEY_PERIOD = 46,
              DSK_KEY_SLASH = 47,
              DSK_KEY_0 = 48,
              DSK_KEY_1 = 49,
              DSK_KEY_2 = 50,
              DSK_KEY_3 = 51,
              DSK_KEY_4 = 52,
              DSK_KEY_5 = 53,
              DSK_KEY_6 = 54,
              DSK_KEY_7 = 55,
              DSK_KEY_8 = 56,
              DSK_KEY_9 = 57,
              DSK_KEY_SEMICOLON = 59,
              DSK_KEY_EQUAL = 61,
              DSK_KEY_A = 65,
              DSK_KEY_B = 66,
              DSK_KEY_C = 67,
              DSK_KEY_D = 68,
              DSK_KEY_E = 69,
              DSK_KEY_F = 70,
              DSK_KEY_G = 71,
              DSK_KEY_H = 72,
              DSK_KEY_I = 73,
              DSK_KEY_J = 74,
              DSK_KEY_K = 75,
              DSK_KEY_L = 76,
              DSK_KEY_M = 77,
              DSK_KEY_N = 78,
              DSK_KEY_O = 79,
              DSK_KEY_P = 80,
              DSK_KEY_Q = 81,
              DSK_KEY_R = 82,
              DSK_KEY_S = 83,
              DSK_KEY_T = 84,
              DSK_KEY_U = 85,
              DSK_KEY_V = 86,
              DSK_KEY_W = 87,
              DSK_KEY_X = 88,
              DSK_KEY_Y = 89,
              DSK_KEY_Z = 90,
              DSK_KEY_LEFT_BRACKET = 91,
              DSK_KEY_BACKSLASH = 92,
              DSK_KEY_RIGHT_BRACKET = 93,
              DSK_KEY_GRAVE_ACCENT = 96,
              DSK_KEY_WORLD_1 = 161,
              DSK_KEY_WORLD_2 = 162,
              DSK_KEY_ESCAPE = 256,
              DSK_KEY_ENTER = 257,
              DSK_KEY_TAB = 258,
              DSK_KEY_BACKSPACE = 259,
              DSK_KEY_INSERT = 260,
              DSK_KEY_DELETE = 261,
              DSK_KEY_RIGHT = 262,
              DSK_KEY_LEFT = 263,
              DSK_KEY_DOWN = 264,
              DSK_KEY_UP = 265,
              DSK_KEY_PAGE_UP = 266,
              DSK_KEY_PAGE_DOWN = 267,
              DSK_KEY_HOME = 268,
              DSK_KEY_END = 269,
              DSK_KEY_CAPS_LOCK = 280,
              DSK_KEY_SCROLL_LOCK = 281,
              DSK_KEY_NUM_LOCK = 282,
              DSK_KEY_PRINT_SCREEN = 283,
              DSK_KEY_PAUSE = 284,
              DSK_KEY_F1 = 290,
              DSK_KEY_F2 = 291,
              DSK_KEY_F3 = 292,
              DSK_KEY_F4 = 293,
              DSK_KEY_F5 = 294,
              DSK_KEY_F6 = 295,
              DSK_KEY_F7 = 296,
              DSK_KEY_F8 = 297,
              DSK_KEY_F9 = 298,
              DSK_KEY_F10 = 299,
              DSK_KEY_F11 = 300,
              DSK_KEY_F12 = 301,
              DSK_KEY_F13 = 302,
              DSK_KEY_F14 = 303,
              DSK_KEY_F15 = 304,
              DSK_KEY_F16 = 305,
              DSK_KEY_F17 = 306,
              DSK_KEY_F18 = 307,
              DSK_KEY_F19 = 308,
              DSK_KEY_F20 = 309,
              DSK_KEY_F21 = 310,
              DSK_KEY_F22 = 311,
              DSK_KEY_F23 = 312,
              DSK_KEY_F24 = 313,
              DSK_KEY_F25 = 314,
              DSK_KEY_KP_0 = 320,
              DSK_KEY_KP_1 = 321,
              DSK_KEY_KP_2 = 322,
              DSK_KEY_KP_3 = 323,
              DSK_KEY_KP_4 = 324,
              DSK_KEY_KP_5 = 325,
              DSK_KEY_KP_6 = 326,
              DSK_KEY_KP_7 = 327,
              DSK_KEY_KP_8 = 328,
              DSK_KEY_KP_9 = 329,
              DSK_KEY_KP_DECIMAL = 330,
              DSK_KEY_KP_DIVIDE = 331,
              DSK_KEY_KP_MULTIPLY = 332,
              DSK_KEY_KP_SUBTRACT = 333,
              DSK_KEY_KP_ADD = 334,
              DSK_KEY_KP_ENTER = 335,
              DSK_KEY_KP_EQUAL = 336,
              DSK_KEY_LEFT_SHIFT = 340,
              DSK_KEY_LEFT_CONTROL = 341,
              DSK_KEY_LEFT_ALT = 342,
              DSK_KEY_LEFT_SUPER = 343,
              DSK_KEY_RIGHT_SHIFT = 344,
              DSK_KEY_RIGHT_CONTROL = 345,
              DSK_KEY_RIGHT_ALT = 346,
              DSK_KEY_RIGHT_SUPER = 347,
              DSK_KEY_MENU = 348
       } DskKey;

       typedef struct DskKeyboard DskKeyboard;

       typedef struct DskKeyboardSettings
       {
              DskWindow *window;
       } DskKeyboardSettings;

       ATK_API void dskCreateKeyboard(DskKeyboard *keyboard, const DskKeyboardSettings *settings);
       ATK_API void dskDestroyKeyboard(DskKeyboard *keyboard);
       ATK_API bool dskKeyboardIsKeyPressed(DskKeyboard *keyboard, DskKey key);
       ATK_API bool dskKeyboardIsKeyReleased(DskKeyboard *keyboard, DskKey key);

       typedef enum DskMouseButton
       {
              DSK_MOUSE_BUTTON_1 = 0,
              DSK_MOUSE_BUTTON_2 = 1,
              DSK_MOUSE_BUTTON_3 = 2,
              DSK_MOUSE_BUTTON_4 = 3,
              DSK_MOUSE_BUTTON_5 = 4,
              DSK_MOUSE_BUTTON_6 = 5,
              DSK_MOUSE_BUTTON_7 = 6,
              DSK_MOUSE_BUTTON_8 = 7,
              DSK_MOUSE_BUTTON_LAST = DSK_MOUSE_BUTTON_8,
              DSK_MOUSE_BUTTON_LEFT = DSK_MOUSE_BUTTON_1,
              DSK_MOUSE_BUTTON_RIGHT = DSK_MOUSE_BUTTON_2,
              DSK_MOUSE_BUTTON_MIDDLE = DSK_MOUSE_BUTTON_3
       } DskMouseButton;

       typedef struct DskMouse DskMouse;

       typedef struct DskMouseSettings
       {
              DskWindow *window;
       } DskMouseSettings;

       ATK_API void dskCreateMouse(DskMouse *mouse, const DskMouseSettings *settings);
       ATK_API void dskDestroyMouse(DskMouse *mouse);
       ATK_API bool dskMouseIsMouseButtonPressed(DskMouse *mouse, DskMouseButton button);
       ATK_API bool dskMouseIsMouseButtonReleased(DskMouse *mouse, DskMouseButton button);
       ATK_API AtkPack2d dskMouseGetCursorPos(DskMouse *mouse);

#ifdef __cplusplus
}
#endif //__cplusplus

struct DskWindow
{
       void *m_handle ATK_HIDE_CPP(= nullptr);
       int m_width ATK_HIDE_CPP(= 0), m_height ATK_HIDE_CPP(= 0);
#ifdef __cplusplus
       DskWindow() : m_handle(nullptr), m_width(0), m_height(0)
       {
       }
       DskWindow(const DskWindowSettings &settings)
       {
              dskCreateWindow(this, &settings);
       }
       DskWindow(const DskWindow &window) = delete; //to avoid "destroy" errors - same window with two instances
       DskWindow(DskWindow &&window)
       {
              m_handle = window.m_handle;
              m_width = window.m_width;
              m_height = window.m_height;
              window.m_handle = nullptr;
       }
       ~DskWindow()
       {
              if (m_handle == nullptr)
                     return;
              dskDestroyWindow(this);
       }
       DskWindow &operator=(const DskWindow &window) = delete;
       DskWindow &operator=(DskWindow &&window)
       {
              m_handle = window.m_handle;
              m_width = window.m_width;
              m_height = window.m_height;
              window.m_handle = nullptr;
              return *this;
       }
       bool create(const DskWindowSettings &settings)
       {
              if (m_handle != nullptr)
                     dskDestroyWindow(this);
              return dskCreateWindow(this, &settings);
       }
       void destroy()
       {
              dskDestroyWindow(this);
       }
       bool shouldClose()
       {
              return dskWindowShouldClose(this);
       }
       void hide()
       {
              dskWindowHide(this);
       }
       void show()
       {
              dskWindowShow(this);
       }
#ifdef ATK_PLATFORM_LINUX
       Window getX11Window()
       {
              return dskWindowGetX11Window(this);
       }
#endif //ATK_PLATFORM_LINUX
       inline const void *handle() const noexcept
       {
              return m_handle;
       }
       inline int width() const noexcept
       {
              return m_width;
       }
       inline int height() const noexcept
       {
              return m_height;
       }
#endif //__cplusplus
};

#define DSK_MAX_KEYS 350
#define DSK_STATE_NOP -1

struct DskKeyboard
{
       DskWindow *m_window ATK_HIDE_CPP(= nullptr);
       int m_keys_states[DSK_MAX_KEYS] ATK_HIDE_CPP(= {DSK_STATE_NOP});
       AtkVector m_keys_released;
#ifdef __cplusplus
       DskKeyboard() : m_window(nullptr), m_keys_states{DSK_STATE_NOP}
       {
       }
       DskKeyboard(const DskKeyboardSettings &settings)
       {
              dskCreateKeyboard(this, &settings);
       }
       DskKeyboard(const DskKeyboard &keyboard) = delete;//only once keyboard
       DskKeyboard(DskKeyboard &&keyboard)
       {
              m_window = keyboard.m_window;
              memcpy(m_keys_states, keyboard.m_keys_states, DSK_MAX_KEYS);
              m_keys_released = std::move(keyboard.m_keys_released);
              keyboard.m_window = nullptr;
       }
       ~DskKeyboard()
       {
              if (m_window == nullptr)
                     return;
              dskDestroyKeyboard(this);
       }
       DskKeyboard &operator=(const DskKeyboard &keyboard) = delete;
       DskKeyboard &operator=(DskKeyboard &&keyboard)
       {
              m_window = keyboard.m_window;
              memcpy(m_keys_states, keyboard.m_keys_states, DSK_MAX_KEYS);
              m_keys_released = std::move(keyboard.m_keys_released);
              keyboard.m_window = nullptr;
              return *this;
       }
       void create(const DskKeyboardSettings &settings)
       {
              if (m_window != nullptr)
                     dskDestroyKeyboard(this);
              dskCreateKeyboard(this, &settings);
       }
       void destroy()
       {
              dskDestroyKeyboard(this);
       }
       bool isKeyPressed(DskKey key)
       {
              return dskKeyboardIsKeyPressed(this, key);
       }
       bool isKeyReleased(DskKey key)
       {
              return dskKeyboardIsKeyReleased(this, key);
       }
#endif //__cplusplus
};

#define DSK_MAX_MOUSE_BUTTONS 8

struct DskMouse
{
       DskWindow *m_window ATK_HIDE_CPP(= nullptr);
       int m_buttons_states[DSK_MAX_MOUSE_BUTTONS] ATK_HIDE_CPP(= {DSK_STATE_NOP});
       AtkVector m_buttons_released;
#ifdef __cplusplus
       DskMouse() : m_window(nullptr), m_buttons_states{DSK_STATE_NOP}
       {
       }
       DskMouse(const DskMouseSettings &settings)
       {
              dskCreateMouse(this, &settings);
       }
       DskMouse(const DskMouse &mouse) = delete;//only once mouse
       DskMouse(DskMouse &&mouse)
       {
              m_window = mouse.m_window;
              memcpy(m_buttons_states, mouse.m_buttons_states, DSK_MAX_MOUSE_BUTTONS);
              m_buttons_released = std::move(mouse.m_buttons_released);
              mouse.m_window = nullptr;
       }
       ~DskMouse()
       {
              if (m_window == nullptr)
                     return;
              dskDestroyMouse(this);
       }
       DskMouse &operator=(const DskMouse &mouse) = delete;//only once mouse
       DskMouse &operator=(DskMouse &&mouse)
       {
              m_window = mouse.m_window;
              memcpy(m_buttons_states, mouse.m_buttons_states, DSK_MAX_MOUSE_BUTTONS);
              m_buttons_released = std::move(mouse.m_buttons_released);
              mouse.m_window = nullptr;
              return *this;
       }
       void create(const DskMouseSettings &settings)
       {
              if (m_window != nullptr)
                     dskDestroyMouse(this);
              dskCreateMouse(this, &settings);
       }
       void destroy()
       {
              dskDestroyMouse(this);
       }
       bool isButtonPressed(DskMouseButton button)
       {
              return dskMouseIsMouseButtonPressed(this, button);
       }
       bool isButtonReleased(DskMouseButton button)
       {
              return dskMouseIsMouseButtonReleased(this, button);
       }
       AtkPack2d getCursorPos()
       {
              return dskMouseGetCursorPos(this);
       }
#endif //__cplusplus
};

#endif //__DESKTOP_H__