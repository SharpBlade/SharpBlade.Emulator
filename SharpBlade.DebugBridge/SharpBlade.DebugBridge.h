// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SHARPBLADEDEBUGBRIDGE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SHARPBLADEDEBUGBRIDGE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SHARPBLADEDEBUGBRIDGE_EXPORTS
#define SHARPBLADEDEBUGBRIDGE_API __declspec(dllexport)
#else
#define SHARPBLADEDEBUGBRIDGE_API __declspec(dllimport)
#endif

// This class is exported from the SharpBlade.DebugBridge.dll
class SHARPBLADEDEBUGBRIDGE_API CSharpBladeDebugBridge {
public:
	CSharpBladeDebugBridge(void);
	// TODO: add your methods here.
};

extern SHARPBLADEDEBUGBRIDGE_API int nSharpBladeDebugBridge;

SHARPBLADEDEBUGBRIDGE_API int fnSharpBladeDebugBridge(void);
