#include "stdafx.h"
#include "emulator.h"
#include "manager.h"

API void SetAppStartedCallback(AppStartedCallback callback)
{
    Manager::SetAppStartedCallback(callback);
}

API void SetAppStoppedCallback(AppStoppedCallback callback)
{
    Manager::SetAppStoppedCallback(callback);
}

API void SetRenderCallback(RenderCallback callback)
{
    Manager::SetRenderCallback(callback);
}

API void SetDynamicKeyImageCallback(DynamicKeyImageCallback callback)
{
    Manager::SetDynamicKeyImageCallback(callback);
}

API void SetTouchpadImageCallback(TouchpadImageCallback callback)
{
    Manager::SetTouchpadImageCallback(callback);
}

API void SetOSGestureUpdateCallback(OSGestureUpdateCallback callback)
{
    Manager::SetOSGestureUpdateCallback(callback);
}

API void SendGesture(RZSBSDK_GESTURETYPE gesture, DWORD count, WORD x, WORD y, WORD z)
{
    Manager::SendGesture(gesture, count, x, y, z);
}

API void SendDynamicKeyChange(RZSBSDK_DKTYPE dk, RZSBSDK_KEYSTATETYPE state)
{
    Manager::SendDynamicKeyChange(dk, state);
}

API void SendAppEvent(RZSBSDK_EVENTTYPETYPE type, DWORD dwParam1, DWORD dwParam2)
{
    Manager::SendAppEvent(type, dwParam1, dwParam2);
}

API void SendKey(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Manager::SendKey(uMsg, wParam, lParam);
}
