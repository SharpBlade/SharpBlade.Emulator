#pragma once

#define RZSB_OK                               S_OK
#define RZSB_UNSUCCESSFUL                     E_FAIL
#define RZSB_INVALID_PARAMETER                E_INVALIDARG
#define RZSB_INVALID_POINTER                  E_POINTER
#define RZSB_ABORTED                          E_ABORT
#define RZSB_NO_INTERFACE                     E_NOINTERFACE
#define RZSB_NOT_IMPLEMENTED                  E_NOTIMPL
#define RZSB_FILE_NOT_FOUND                   ERROR_FILE_NOT_FOUND

#define RZSB_SUCCESS(a) (S_OK == (a))
#define RZSB_FAILED(a)  (S_OK != (a))

#define RZSB_GENERIC_BASE                     0x20000000
#define RZSB_FILE_ZERO_SIZE                   (RZSB_GENERIC_BASE + 0x1)
#define RZSB_FILE_INVALID_NAME                (RZSB_GENERIC_BASE + 0x2)
#define RZSB_FILE_INVALID_TYPE                (RZSB_GENERIC_BASE + 0x3)
#define RSZB_FILE_READ_ERROR                  (RZSB_GENERIC_BASE + 0x4)
#define RZSB_FILE_INVALID_FORMAT              (RZSB_GENERIC_BASE + 0x5)
#define RZSB_FILE_INVALID_LENGTH              (RZSB_GENERIC_BASE + 0x6)
#define RZSB_FILE_NAMEPATH_TOO_LONG           (RZSB_GENERIC_BASE + 0x7)
#define RZSB_IMAGE_INVALID_SIZE               (RZSB_GENERIC_BASE + 0x8)
#define RZSB_IMAGE_INVALID_DATA               (RZSB_GENERIC_BASE + 0x9)
#define RZSB_WIN_VERSION_INVALID              (RZSB_GENERIC_BASE + 0xa)

#define RZSB_CALLBACK_BASE                    0x20010000
#define RZSB_CALLBACK_NOT_SET                 (RZSB_CALLBACK_BASE + 0x1)
#define RZSB_CALLBACK_ALREADY_SET             (RZSB_CALLBACK_BASE + 0x2)
#define RZSB_CALLBACK_REMOTE_FAIL             (RZSB_CALLBACK_BASE + 0x3)

#define RZSB_CONTROL_BASE_ERROR               0x20020000
#define RZSB_CONTROL_NOT_LOCKED               (RZSB_CONTROL_BASE_ERROR + 0x01)
#define RZSB_CONTROL_LOCKED                   (RZSB_CONTROL_BASE_ERROR + 0x02)
#define RZSB_CONTROL_ALREADY_LOCKED           (RZSB_CONTROL_BASE_ERROR + 0x03)
#define RZSB_CONTROL_PREEMPTED                (RZSB_CONTROL_BASE_ERROR + 0x04)

#define RZSB_DK_BASE_ERROR                    0x20040000
#define RZSB_DK_INVALID_KEY                   (RZSB_DK_BASE_ERROR + 0x1)
#define RZSB_DK_INVALID_KEY_STATE             (RZSB_DK_BASE_ERROR + 0x2)

#define RZSB_TOUCHPAD_BASE_ERROR              0x20080000
#define RZSB_TOUCHPAD_INVALID_GESTURE         (RZSB_TOUCHPAD_BASE_ERROR + 0x1)

#define RZSB_INTERNAL_BASE_ERROR              0x20100000
#define RZSB_ALREADY_STARTED                  (RZSB_INTERNAL_BASE_ERROR + 0x1)
#define RZSB_NOT_STARTED                      (RZSB_INTERNAL_BASE_ERROR + 0x2)
#define RZSB_CONNECTION_ERROR                 (RZSB_INTERNAL_BASE_ERROR + 0x3)
#define RZSB_INTERNAL_ERROR                   (RZSB_INTERNAL_BASE_ERROR + 0x4)

#define RZSB_WINRENDER_BASE_ERROR             0x20200000
#define RZSB_WINRENDER_OUT_OF_RESOURCES       (RZSB_WINRENDER_BASE_ERROR + 0x01)
#define RZSB_WINRENDER_THREAD_FAILED          (RZSB_WINRENDER_BASE_ERROR + 0x02)
#define RZSB_WINRENDER_WRONG_MODEL            (RZSB_WINRENDER_BASE_ERROR + 0x03)
