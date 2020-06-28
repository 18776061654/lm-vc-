// W32D.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "W32D.h"


// This is an example of an exported variable
W32D_API int nW32D=0;

// This is an example of an exported function.
W32D_API int fnW32D(void)
{
	return 42;
}

W32D_API int GetInt()
{
	return 2020;
}

// This is the constructor of a class that has been exported.
// see W32D.h for the class definition
CW32D::CW32D()
{
	return;
}
