#pragma once

#include <Windows.h>

#define MAX_SUPPORTED_SURFACES 2

#define TARGET_MASK(x) ((1 << 16) | (x))

typedef enum _SWITCHBLADE_HARDWARE_TYPE_
{
    HARDWARETYPE_INVALID = 0,
    HARDWARETYPE_SWITCHBLADE,
    HARDWARETYPE_UNDEFINED
} SWITCHBLADEHARDWARETYPE, *PSWITCHBLADEHARDWARETYPE;

typedef enum _RZSBSDK_KEYSTATE
{
    RZSBSDK_KEYSTATE_NONE = 0,
    RZSBSDK_KEYSTATE_UP,
    RZSBSDK_KEYSTATE_DOWN,
    RZSBSDK_KEYSTATE_HOLD,
    RZSBSDK_KEYSTATE_INVALID,
} RZSBSDK_KEYSTATETYPE, *PRZSBSDK_KEYSTATETYPE;

typedef enum _RZSDKSTATICKEYTYPE
{
    RZSBSDK_STATICKEY_NONE = 0,
    RZSBSDK_STATICKEY_RAZER,
    RZSBSDK_STATICKEY_GAME,
    RZSBSDK_STATICKEY_MACRO,
    RZSBSDK_STATICKEY_INVALID
} RZSBSDK_STATICKEYTYPE, *PRZSBSDK_STATICKEYTYPE;

typedef enum _RZSBSDK_DKTYPE
{
    RZSBSDK_DK_NONE = 0,
    RZSBSDK_DK_1,
    RZSBSDK_DK_2,
    RZSBSDK_DK_3,
    RZSBSDK_DK_4,
    RZSBSDK_DK_5,
    RZSBSDK_DK_6,
    RZSBSDK_DK_7,
    RZSBSDK_DK_8,
    RZSBSDK_DK_9,
    RZSBSDK_DK_10,
    RZSBSDK_DK_INVALID,
    RZSBSDK_DK_COUNT = 10
} RZSBSDK_DKTYPE, *PRZSBSDK_DKTYPE;

enum RZSBSDK_DISPLAY
{
    RZSBSDK_DISPLAY_WIDGET = TARGET_MASK(RZSBSDK_DK_NONE),
    RZSBSDK_DISPLAY_DK_1 =   TARGET_MASK(RZSBSDK_DK_1),
    RZSBSDK_DISPLAY_DK_2 =   TARGET_MASK(RZSBSDK_DK_2),
    RZSBSDK_DISPLAY_DK_3 =   TARGET_MASK(RZSBSDK_DK_3),
    RZSBSDK_DISPLAY_DK_4 =   TARGET_MASK(RZSBSDK_DK_4),
    RZSBSDK_DISPLAY_DK_5 =   TARGET_MASK(RZSBSDK_DK_5),
    RZSBSDK_DISPLAY_DK_6 =   TARGET_MASK(RZSBSDK_DK_6),
    RZSBSDK_DISPLAY_DK_7 =   TARGET_MASK(RZSBSDK_DK_7),
    RZSBSDK_DISPLAY_DK_8 =   TARGET_MASK(RZSBSDK_DK_8),
    RZSBSDK_DISPLAY_DK_9 =   TARGET_MASK(RZSBSDK_DK_9),
    RZSBSDK_DISPLAY_DK_10 =  TARGET_MASK(RZSBSDK_DK_10),
};

enum PIXEL_TYPE { RGB565 = 0 };

typedef enum _RZSBSDK_GESTURETYPE
{
    RZSBSDK_GESTURE_NONE =    0x00000000,
    RZSBSDK_GESTURE_PRESS =   0x00000001,
    RZSBSDK_GESTURE_TAP =     0x00000002,
    RZSBSDK_GESTURE_FLICK =   0x00000004,
    RZSBSDK_GESTURE_ZOOM =    0x00000008,
    RZSBSDK_GESTURE_ROTATE =  0x00000010,
    RZSBSDK_GESTURE_MOVE =    0x00000020,
    RZSBSDK_GESTURE_HOLD =    0x00000040,
    RZSBSDK_GESTURE_RELEASE = 0x00000080,
    RZSBSDK_GESTURE_SCROLL =  0x00000100,
    RZSBSDK_GESTURE_ALL =     0xFFFF
} RZSBSDK_GESTURETYPE, *PRZSBSDK_GESTURETYPE;

typedef enum _RZSBSDK_EVENTTYPE
{
    RZSBSDK_EVENT_NONE = 0,
    RZSBSDK_EVENT_ACTIVATED,
    RZSBSDK_EVENT_DEACTIVATED,
    RZSBSDK_EVENT_CLOSE,
    RZSBSDK_EVENT_EXIT,
    RZSBSDK_EVENT_INVALID,
} RZSBSDK_EVENTTYPETYPE, *PRZSBSDK_EVENTTYPETYPE;

typedef enum _RZSBSDK_DIRECTIONTYPE
{
    RZSBSDK_DIRECTION_NONE = 0,
    RZSBSDK_DIRECTION_LEFT,
    RZSBSDK_DIRECTION_RIGHT,
    RZSBSDK_DIRECTION_UP,
    RZSBSDK_DIRECTION_DOWN,
    RZSBSDK_DIRECTION_INVALID
} RZSBSDK_DIRECTIONTYPE, *PRZSBSDK_DIRECTIONTYPE;

typedef struct _RZSBSDK_QUERYCAPABILITIES
{
    DWORD                   qc_version;
    DWORD                   qc_BEVersion;
    SWITCHBLADEHARDWARETYPE qc_HardwareType;
    DWORD                   qc_numSurfaces;
    POINT                   qc_surfacegeometry[MAX_SUPPORTED_SURFACES];
    DWORD                   qc_pixelformat[MAX_SUPPORTED_SURFACES];
    BYTE                    qc_numDynamicKeys;
    POINT                   qc_DynamicKeyArrangement;
    POINT                   qc_keyDynamicKeySize;
} RZSBSDK_QUERYCAPABILITIES, *PRZSBSDK_QUERYCAPABILITIES;

typedef struct _RZSBSDK_BUFFERPARAMS
{
    PIXEL_TYPE PixelType;
    DWORD DataSize;
    BYTE *pData;
} RZSBSDK_BUFFERPARAMS, *PRZSBSDK_BUFFERPARAMS;

typedef HRESULT(CALLBACK *AppEventCallbackType) (RZSBSDK_EVENTTYPETYPE type, DWORD dwParam1, DWORD dwParam2);
typedef HRESULT(CALLBACK *DynamicKeyCallbackFunctionType)(RZSBSDK_DKTYPE dk, RZSBSDK_KEYSTATETYPE state);
typedef HRESULT(CALLBACK *KeyboardCallbackFunctionType)(UINT uMsg, WPARAM wParam, LPARAM lParam);
typedef HRESULT(CALLBACK *TouchpadGestureCallbackFunctionType)(RZSBSDK_GESTURETYPE gesture, DWORD count, WORD x, WORD y, WORD z);

extern "C"
{
    extern HRESULT RzSBStart();
    extern HRESULT RzSBStop();
    extern HRESULT RzSBQueryCapabilities(PRZSBSDK_QUERYCAPABILITIES caps);
    extern HRESULT RzSBRenderBuffer(RZSBSDK_DISPLAY disp, RZSBSDK_BUFFERPARAMS *params);

    extern HRESULT RzSBSetImageDynamicKey(RZSBSDK_DKTYPE dk, RZSBSDK_KEYSTATETYPE state, LPWSTR path);
    extern HRESULT RzSBSetImageTouchpad(LPWSTR path);

    extern HRESULT RzSBEnableGesture(RZSBSDK_GESTURETYPE gesture, bool enable);
    extern HRESULT RzSBEnableOSGesture(RZSBSDK_GESTURETYPE gesture, bool enable);

    extern HRESULT RzSBAppEventSetCallback(AppEventCallbackType callback);
    extern HRESULT RzSBDynamicKeySetCallback(DynamicKeyCallbackFunctionType callback);
    extern HRESULT RzSBGestureSetCallback(TouchpadGestureCallbackFunctionType callback);

    extern HRESULT RzSBKeyboardCaptureSetCallback(KeyboardCallbackFunctionType callback);
    extern HRESULT RzSBCaptureKeyboard(bool enable);
}
