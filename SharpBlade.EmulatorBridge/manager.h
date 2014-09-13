#pragma once

#include "razerapi.h"
#include "emulator.h"

class Manager
{
public:
    static void SetGesture(RZSBSDK_GESTURETYPE gesture, bool enabled);
    static void SetOSGesture(RZSBSDK_GESTURETYPE gesture, bool enabled);

    static void SetAppEventCallback(AppEventCallbackType callback);
    static void SetDynamicKeyCallback(DynamicKeyCallbackFunctionType callback);
    static void SetGestureCallback(TouchpadGestureCallbackFunctionType callback);
    static void SetKeyboardCallback(KeyboardCallbackFunctionType callback);

    static void SetKeyboardCapture(bool enabled);

    static void NotifyStart(int pid);
    static void NotifyStop(int pid);
    static void NotifyRender(RZSBSDK_DISPLAY disp, PRZSBSDK_BUFFERPARAMS params);
    static void NotifyDynamicKeyImageChanged(RZSBSDK_DKTYPE dk, RZSBSDK_KEYSTATETYPE state, LPWSTR path);
    static void NotifyTouchpadImageChanged(LPWSTR path);

    static void SetAppStartedCallback(AppStartedCallback callback);
    static void SetAppStoppedCallback(AppStoppedCallback callback);
    static void SetRenderCallback(RenderCallback callback);
    static void SetDynamicKeyImageCallback(DynamicKeyImageCallback callback);
    static void SetTouchpadImageCallback(TouchpadImageCallback callback);
    static void SetOSGestureUpdateCallback(OSGestureUpdateCallback callback);

    static void SendGesture(RZSBSDK_GESTURETYPE gesture, DWORD count, WORD x, WORD y, WORD z);

    static void SendAppEvent(RZSBSDK_EVENTTYPETYPE type, DWORD dwParam1, DWORD dwParam2);

    static void SendDynamicKeyChange(RZSBSDK_DKTYPE dk, RZSBSDK_KEYSTATETYPE state);

    static void SendKey(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    Manager() {};

    static RZSBSDK_GESTURETYPE activeGestures;
    static RZSBSDK_GESTURETYPE activeOSGestures;
    
    static AppEventCallbackType appEventCallback;
    static DynamicKeyCallbackFunctionType dynamicKeyCallback;
    static TouchpadGestureCallbackFunctionType gestureCallback;
    static KeyboardCallbackFunctionType keyboardCallback;
    
    static bool keyboardCaptureActive;

    static AppStartedCallback appStartedCallback;
    static AppStoppedCallback appStoppedCallback;
    static RenderCallback renderCallback;
    static DynamicKeyImageCallback dynamicKeyImageCallback;
    static TouchpadImageCallback touchpadImageCallback;
    static OSGestureUpdateCallback osGestureUpdateCallback;
};
