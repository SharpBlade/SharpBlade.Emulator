#pragma once

#include "razerapi.h"

#ifdef EXPORTS
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

typedef void (CALLBACK *AppStartedCallback)(int pid);
typedef void (CALLBACK *AppStoppedCallback)(int pid);
typedef void (CALLBACK *RenderCallback)(RZSBSDK_DISPLAY disp, PRZSBSDK_BUFFERPARAMS params);
typedef void (CALLBACK *DynamicKeyImageCallback)(RZSBSDK_DKTYPE dk, RZSBSDK_KEYSTATETYPE state, LPWSTR path);
typedef void (CALLBACK *TouchpadImageCallback)(LPWSTR path);
typedef void (CALLBACK *OSGestureUpdateCallback)(RZSBSDK_GESTURETYPE gestures);

extern "C"
{
    API void SetAppStartedCallback(AppStartedCallback callback);
    API void SetAppStoppedCallback(AppStoppedCallback callback);
    API void SetRenderCallback(RenderCallback callback);
    API void SetDynamicKeyImageCallback(DynamicKeyImageCallback callback);
    API void SetTouchpadImageCallback(TouchpadImageCallback callback);
    API void SetOSGestureUpdateCallback(OSGestureUpdateCallback callback);

    API void SendGesture(RZSBSDK_GESTURETYPE gesture, DWORD count, WORD x, WORD y, WORD z);

    API void SendDynamicKeyChange(RZSBSDK_DKTYPE dk, RZSBSDK_KEYSTATETYPE state);

    API void SendAppEvent(RZSBSDK_EVENTTYPETYPE type, DWORD dwParam1, DWORD dwParam2);

    API void SendKey(UINT uMsg, WPARAM wParam, LPARAM lParam);
}
