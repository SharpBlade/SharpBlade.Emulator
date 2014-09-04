// SharpBlade.DebugBridge.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SharpBlade.DebugBridge.h"

// This is an example of an exported variable
SHARPBLADEDEBUGBRIDGE_API int nSharpBladeDebugBridge=0;

// This is an example of an exported function.
SHARPBLADEDEBUGBRIDGE_API int fnSharpBladeDebugBridge(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see SharpBlade.DebugBridge.h for the class definition
CSharpBladeDebugBridge::CSharpBladeDebugBridge()
{
	return;
}
