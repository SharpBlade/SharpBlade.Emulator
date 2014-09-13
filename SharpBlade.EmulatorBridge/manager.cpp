#include "manager.h"

RZSBSDK_GESTURETYPE Manager::activeGestures = RZSBSDK_GESTURE_NONE;
RZSBSDK_GESTURETYPE Manager::activeOSGestures = RZSBSDK_GESTURE_NONE;

AppEventCallbackType Manager::appEventCallback = NULL;
DynamicKeyCallbackFunctionType Manager::dynamicKeyCallback = NULL;
TouchpadGestureCallbackFunctionType Manager::gestureCallback = NULL;
KeyboardCallbackFunctionType Manager::keyboardCallback = NULL;

bool Manager::keyboardCaptureActive = false;

AppStartedCallback Manager::appStartedCallback = NULL;
AppStoppedCallback Manager::appStoppedCallback = NULL;
RenderCallback Manager::renderCallback = NULL;
DynamicKeyImageCallback Manager::dynamicKeyImageCallback = NULL;
TouchpadImageCallback Manager::touchpadImageCallback = NULL;
OSGestureUpdateCallback Manager::osGestureUpdateCallback = NULL;

void Manager::SetGesture(RZSBSDK_GESTURETYPE gesture, bool enabled)
{
    if ((gesture == RZSBSDK_GESTURE_ALL || gesture == RZSBSDK_GESTURE_NONE) && enabled)
        activeGestures = gesture;
    else if (gesture == RZSBSDK_GESTURE_ALL && !enabled)
        activeGestures = RZSBSDK_GESTURE_NONE;
    else if (gesture == RZSBSDK_GESTURE_NONE && !enabled)
        activeGestures = RZSBSDK_GESTURE_ALL;
    else if (enabled)
        activeGestures = (RZSBSDK_GESTURETYPE)(activeGestures | gesture);
    else
        activeGestures = (RZSBSDK_GESTURETYPE)(activeGestures & ~gesture);
}

void Manager::SetOSGesture(RZSBSDK_GESTURETYPE gesture, bool enabled)
{
    if ((gesture == RZSBSDK_GESTURE_ALL || gesture == RZSBSDK_GESTURE_NONE) && enabled)
        activeOSGestures = gesture;
    else if (gesture == RZSBSDK_GESTURE_ALL && !enabled)
        activeOSGestures = RZSBSDK_GESTURE_NONE;
    else if (gesture == RZSBSDK_GESTURE_NONE && !enabled)
        activeOSGestures = RZSBSDK_GESTURE_ALL;
    else if (enabled)
        activeOSGestures = (RZSBSDK_GESTURETYPE)(activeOSGestures | gesture);
    else
        activeOSGestures = (RZSBSDK_GESTURETYPE)(activeOSGestures & ~gesture);

    OSGestureUpdateCallback callback = osGestureUpdateCallback;
    if (callback != NULL)
        callback(activeOSGestures);
}

void Manager::SetAppEventCallback(AppEventCallbackType callback)
{
    appEventCallback = callback;
}

void Manager::SetDynamicKeyCallback(DynamicKeyCallbackFunctionType callback)
{
    dynamicKeyCallback = callback;
}

void Manager::SetGestureCallback(TouchpadGestureCallbackFunctionType callback)
{
    gestureCallback = callback;
}

void Manager::SetKeyboardCallback(KeyboardCallbackFunctionType callback)
{
    keyboardCallback = callback;
}

void Manager::SetKeyboardCapture(bool enabled)
{
    keyboardCaptureActive = enabled;
}

void Manager::NotifyStart(int pid)
{
    AppStartedCallback callback = appStartedCallback;
    if (callback != NULL)
        callback(pid);
}

void Manager::NotifyStop(int pid)
{
    AppStoppedCallback callback = appStoppedCallback;
    if (callback != NULL)
        callback(pid);
}

void Manager::NotifyRender(RZSBSDK_DISPLAY disp, PRZSBSDK_BUFFERPARAMS params)
{
    RenderCallback callback = renderCallback;
    if (callback != NULL)
        callback(disp, params);
}

void Manager::NotifyDynamicKeyImageChanged(RZSBSDK_DKTYPE dk, RZSBSDK_KEYSTATETYPE state, LPWSTR path)
{
    DynamicKeyImageCallback callback = dynamicKeyImageCallback;
    if (callback != NULL)
        callback(dk, state, path);
}

void Manager::NotifyTouchpadImageChanged(LPWSTR path)
{
    TouchpadImageCallback callback = touchpadImageCallback;
    if (callback != NULL)
        callback(path);
}

void Manager::SetAppStartedCallback(AppStartedCallback callback)
{
    appStartedCallback = callback;
}

void Manager::SetAppStoppedCallback(AppStoppedCallback callback)
{
    appStoppedCallback = callback;
}

void Manager::SetRenderCallback(RenderCallback callback)
{
    renderCallback = callback;
}

void Manager::SetDynamicKeyImageCallback(DynamicKeyImageCallback callback)
{
    dynamicKeyImageCallback = callback;
}

void Manager::SetTouchpadImageCallback(TouchpadImageCallback callback)
{
    touchpadImageCallback = callback;
}

void Manager::SetOSGestureUpdateCallback(OSGestureUpdateCallback callback)
{
    osGestureUpdateCallback = callback;
}

void Manager::SendGesture(RZSBSDK_GESTURETYPE gesture, DWORD count, WORD x, WORD y, WORD z)
{
    if ((activeGestures & gesture) != gesture)
        return;

    TouchpadGestureCallbackFunctionType callback = gestureCallback;
    if (callback != NULL)
        callback(gesture, count, x, y, z);
}

void Manager::SendAppEvent(RZSBSDK_EVENTTYPETYPE type, DWORD dwParam1, DWORD dwParam2)
{
    AppEventCallbackType callback = appEventCallback;
    if (callback != NULL)
        callback(type, dwParam1, dwParam2);
}

void Manager::SendDynamicKeyChange(RZSBSDK_DKTYPE dk, RZSBSDK_KEYSTATETYPE state)
{
    DynamicKeyCallbackFunctionType callback = dynamicKeyCallback;
    if (callback != NULL)
        callback(dk, state);
}

void Manager::SendKey(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (!keyboardCaptureActive)
        return;

    KeyboardCallbackFunctionType callback = keyboardCallback;
    if (callback != NULL)
        callback(uMsg, wParam, lParam);
}
