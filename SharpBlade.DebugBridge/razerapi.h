#pragma once

#include <Windows.h>

typedef HRESULT(CALLBACK *AppEventCallbackType) (RZSBSDK_EVENTTYPETYPE, DWORD, DWORD);
typedef HRESULT(CALLBACK *DynamicKeyCallbackFunctionType)(RZSBSDK_DKTYPE, RZSBSDK_KEYSTATETYPE);
typedef HRESULT(CALLBACK *KeyboardCallbackFunctionType)(UINT uMsg, WPARAM wParam, LPARAM lParam);
typedef HRESULT(CALLBACK *TouchpadGestureCallbackFunctionType)(RZSBSDK_GESTURETYPE, DWORD, WORD, WORD, WORD);

extern "C"
{
    extern HRESULT RzSBStart();
    extern HRESULT RzSBStop();
    extern HRESULT RzSBQueryCapabilities(PRZSBSDK_QUERYCAPABILITIES);
    extern HRESULT RzSBRenderBuffer(RZSBSDK_DISPLAY, RZSBSDK_BUFFERPARAMS *);

    extern HRESULT RzSBSetImageDynamicKey(RZSBSDK_DKTYPE, RZSBSDK_KEYSTATETYPE, LPWSTR);
    extern HRESULT RzSBSetImageTouchpad(LPWSTR);

    extern HRESULT RzSBEnableGesture(RZSBSDK_GESTURETYPE, bool);
    extern HRESULT RzSBEnableOSGesture(RZSBSDK_GESTURETYPE, bool);

    extern HRESULT RzSBAppEventSetCallback(AppEventCallbackType);
    extern HRESULT RzSBDynamicKeySetCallback(DynamicKeyCallbackFunctionType);
    extern HRESULT RzSBGestureSetCallback(TouchpadGestureCallbackFunctionType);

    extern HRESULT RzSBKeyboardCaptureSetCallback(KeyboardCallbackFunctionType);
    extern HRESULT RzSBCaptureKeyboard(bool);
}
