#ifndef __DESKTOP_H__
#define __DESKTOP_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#ifndef __ATK_H__
#include "atk.h"
#endif //__ATK_H__

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
              if (m_handle != nullptr)
              {
                     dskDestroyWindow(this);
              }
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

#endif //__DESKTOP_H__