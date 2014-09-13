#include "stdafx.h"
#include "razerapi.h"
#include "razerapi_errors.h"

#define VERSION 512
#define BEVERSION 256

#define SWITCHBLADE_DYNAMIC_KEYS_PER_ROW 5
#define SWITCHBLADE_DYNAMIC_KEYS_ROWS    2
#define SWITCHBLADE_DYNAMIC_KEY_X_SIZE   115
#define SWITCHBLADE_DYNAMIC_KEY_Y_SIZE   115
#define SWITCHBLADE_DK_SIZE_IMAGEDATA    (SWITCHBLADE_DYNAMIC_KEY_X_SIZE * SWITCHBLADE_DYNAMIC_KEY_Y_SIZE * sizeof(WORD))

#define SWITCHBLADE_TOUCHPAD_X_SIZE         800
#define SWITCHBLADE_TOUCHPAD_Y_SIZE         480
#define SWITCHBLADE_TOUCHPAD_SIZE_IMAGEDATA (SWITCHBLADE_TOUCHPAD_X_SIZE * SWITCHBLADE_TOUCHPAD_Y_SIZE * sizeof(WORD))

#define SWITCHBLADE_DISPLAY_COLOR_DEPTH 16

#define MAX_STRING_LENGTH 260

#define PIXEL_FORMAT_INVALID 0
#define PIXEL_FORMAT_RGB_565 1

RZSBSDK_GESTURETYPE activeGestures = RZSBSDK_GESTURE_NONE;
RZSBSDK_GESTURETYPE activeOSGestures = RZSBSDK_GESTURE_NONE;

extern HRESULT RzSBStart()
{
    return RZSB_OK;
}

extern HRESULT RzSBStop()
{
    return RZSB_OK;
}

extern HRESULT RzSBQueryCapabilities(PRZSBSDK_QUERYCAPABILITIES caps)
{
    caps->qc_version = VERSION;
    caps->qc_BEVersion = BEVERSION;
    caps->qc_HardwareType = HARDWARETYPE_SWITCHBLADE;
    caps->qc_numSurfaces = MAX_SUPPORTED_SURFACES;
    caps->qc_surfacegeometry[0] = POINT{ SWITCHBLADE_TOUCHPAD_X_SIZE, SWITCHBLADE_TOUCHPAD_Y_SIZE };
    caps->qc_surfacegeometry[1] = POINT{ 0, 0 };
    caps->qc_pixelformat[0] = PIXEL_FORMAT_RGB_565;
    caps->qc_pixelformat[1] = PIXEL_FORMAT_INVALID;
    caps->qc_numDynamicKeys = SWITCHBLADE_DYNAMIC_KEYS_PER_ROW * SWITCHBLADE_DYNAMIC_KEYS_ROWS;
    caps->qc_DynamicKeyArrangement = POINT{ SWITCHBLADE_DYNAMIC_KEYS_PER_ROW, SWITCHBLADE_DYNAMIC_KEYS_ROWS };
    caps->qc_keyDynamicKeySize = POINT{ SWITCHBLADE_DYNAMIC_KEY_X_SIZE, SWITCHBLADE_DYNAMIC_KEY_Y_SIZE };

    return RZSB_OK;
}

extern HRESULT RzSBRenderBuffer(RZSBSDK_DISPLAY disp, RZSBSDK_BUFFERPARAMS *params)
{
    return RZSB_OK;
}

extern HRESULT RzSBSetImageDynamicKey(RZSBSDK_DKTYPE dk, RZSBSDK_KEYSTATETYPE state, LPWSTR path)
{
    return RZSB_OK;
}

extern HRESULT RzSBSetImageTouchpad(LPWSTR path)
{
    return RZSB_OK;
}

extern HRESULT RzSBEnableGesture(RZSBSDK_GESTURETYPE gesture, bool enable)
{
    if ((gesture == RZSBSDK_GESTURE_ALL || gesture == RZSBSDK_GESTURE_NONE) && enable)
        activeGestures = gesture;
    else if (gesture == RZSBSDK_GESTURE_ALL && !enable)
        activeGestures = RZSBSDK_GESTURE_NONE;
    else if (gesture == RZSBSDK_GESTURE_NONE && !enable)
        activeGestures = RZSBSDK_GESTURE_ALL;
    else if (enable)
        activeGestures = (RZSBSDK_GESTURETYPE)(activeGestures | gesture);
    else
        activeGestures = (RZSBSDK_GESTURETYPE)(activeGestures & ~gesture);

    return RZSB_OK;
}

extern HRESULT RzSBEnableOSGesture(RZSBSDK_GESTURETYPE gesture, bool enable)
{
    if ((gesture == RZSBSDK_GESTURE_ALL || gesture == RZSBSDK_GESTURE_NONE) && enable)
        activeOSGestures = gesture;
    else if (gesture == RZSBSDK_GESTURE_ALL && !enable)
        activeOSGestures = RZSBSDK_GESTURE_NONE;
    else if (gesture == RZSBSDK_GESTURE_NONE && !enable)
        activeOSGestures = RZSBSDK_GESTURE_ALL;
    else if (enable)
        activeOSGestures = (RZSBSDK_GESTURETYPE)(activeGestures | gesture);
    else
        activeOSGestures = (RZSBSDK_GESTURETYPE)(activeGestures & ~gesture);

    return RZSB_OK;
}

extern HRESULT RzSBAppEventSetCallback(AppEventCallbackType callback)
{
    return RZSB_OK;
}

extern HRESULT RzSBDynamicKeySetCallback(DynamicKeyCallbackFunctionType callback)
{
    return RZSB_OK;
}

extern HRESULT RzSBGestureSetCallback(TouchpadGestureCallbackFunctionType callback)
{
    return RZSB_OK;
}

extern HRESULT RzSBKeyboardCaptureSetCallback(KeyboardCallbackFunctionType callback)
{
    return RZSB_OK;
}

extern HRESULT RzSBCaptureKeyboard(bool enable)
{
    return RZSB_OK;
}
