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

       typedef struct DskKeyboard DskKeyboard;

       typedef struct DskKeyboardSettings
       {
              DskWindow *window;
       } DskKeyboardSettings;

       ATK_API void dskCreateKeyboard(DskKeyboard *keyboard, const DskKeyboardSettings *settings);
       ATK_API void dskDestroyKeyboard(DskKeyboard *keyboard);
       ATK_API bool dskKeyboardIsKeyPressed(DskKeyboard *keyboard, int key);
       ATK_API bool dskKeyboardIsKeyReleased(DskKeyboard *keyboard, int key);

       typedef struct DskMouse DskMouse;

       typedef struct DskMouseSettings
       {
              DskWindow *window;
       } DskMouseSettings;

       ATK_API void dskCreateMouse(DskMouse *mouse, const DskMouseSettings *settings);
       ATK_API void dskDestroyMouse(DskMouse *mouse);
       ATK_API bool dskMouseIsMouseButtonPressed(DskMouse *mouse, int button);
       ATK_API bool dskMouseIsMouseButtonReleased(DskMouse *mouse, int button);
       ATK_API AtkPack2d dskMouseGetCursorPos(DskMouse *mouse);

#ifdef __cplusplus
}
#endif //__cplusplus

struct DskWindow
{
       void *m_handle ATK_HIDE_CPP(= nullptr);
       int m_width ATK_HIDE_CPP(= 0), m_height ATK_HIDE_CPP(= 0);
#ifdef __cplusplus
       DskWindow()
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
              destroy();
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
              destroy();
              return dskCreateWindow(this, &settings);
       }
       void destroy()
       {
              if (m_handle == nullptr)
                     return;
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

struct DskKeyboard
{
       DskWindow *m_window ATK_HIDE_CPP(= nullptr);
       AtkVector m_key_pressed, m_key_released;
#ifdef __cplusplus
       DskKeyboard()
       {
       }
       DskKeyboard(const DskKeyboardSettings &settings)
       {
              dskCreateKeyboard(this, &settings);
       }
       DskKeyboard(const DskKeyboard &keyboard)
       {
              m_window = keyboard.m_window;
              m_key_pressed = keyboard.m_key_pressed;
              m_key_released = keyboard.m_key_released;
       }
       DskKeyboard(DskKeyboard &&keyboard)
       {
              m_window = keyboard.m_window;
              m_key_pressed = std::move(keyboard.m_key_pressed);
              m_key_released = std::move(keyboard.m_key_released);
              keyboard.m_window = nullptr;
       }
       ~DskKeyboard()
       {
              destroy();
       }
       DskKeyboard &operator=(const DskKeyboard &keyboard)
       {
              m_window = keyboard.m_window;
              m_key_pressed = keyboard.m_key_pressed;
              m_key_released = keyboard.m_key_released;
              return *this;
       }
       DskKeyboard &operator=(DskKeyboard &&keyboard)
       {
              m_window = keyboard.m_window;
              m_key_pressed = std::move(keyboard.m_key_pressed);
              m_key_released = std::move(keyboard.m_key_released);
              keyboard.m_window = nullptr;
              return *this;
       }
       void create(const DskKeyboardSettings &settings)
       {
              destroy();
              dskCreateKeyboard(this, &settings);
       }
       void destroy()
       {
              if (m_window == nullptr)
                     return;
              dskDestroyKeyboard(this);
       }
       bool isKeyPressed(int key)
       {
              return dskKeyboardIsKeyPressed(this, key);
       }
       bool isKeyReleased(int key)
       {
              return dskKeyboardIsKeyReleased(this, key);
       }
#endif //__cplusplus
};

struct DskMouse
{
       DskWindow *m_window ATK_HIDE_CPP(= nullptr);
       AtkVector m_button_pressed, m_button_released;
#ifdef __cplusplus
       DskMouse()
       {
       }
       DskMouse(const DskMouseSettings &settings)
       {
              dskCreateMouse(this, &settings);
       }
       DskMouse(const DskMouse &mouse)
       {
              m_window = mouse.m_window;
              m_button_pressed = mouse.m_button_pressed;
              m_button_released = mouse.m_button_released;
       }
       DskMouse(DskMouse &&mouse)
       {
              m_window = mouse.m_window;
              m_button_pressed = std::move(mouse.m_button_pressed);
              m_button_released = std::move(mouse.m_button_released);
              mouse.m_window = nullptr;
       }
       ~DskMouse()
       {
              destroy();
       }
       DskMouse &operator=(const DskMouse &mouse)
       {
              m_window = mouse.m_window;
              m_button_pressed = mouse.m_button_pressed;
              m_button_released = mouse.m_button_released;
              return *this;
       }
       DskMouse &operator=(DskMouse &&mouse)
       {
              m_window = mouse.m_window;
              m_button_pressed = std::move(mouse.m_button_pressed);
              m_button_released = std::move(mouse.m_button_released);
              mouse.m_window = nullptr;
              return *this;
       }
       void create(const DskMouseSettings &settings)
       {
              destroy();
              dskCreateMouse(this, &settings);
       }
       void destroy()
       {
              if (m_window == nullptr)
                     return;
              dskDestroyMouse(this);
       }
       bool isButtonPressed(int button)
       {
              return dskMouseIsMouseButtonPressed(this, button);
       }
       bool isButtonReleased(int button)
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