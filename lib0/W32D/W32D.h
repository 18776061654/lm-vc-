// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the W32D_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// W32D_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef W32D_EXPORTS
#define W32D_API __declspec(dllexport)
#else
#define W32D_API __declspec(dllimport)
#endif

// This class is exported from the W32D.dll
class W32D_API CW32D {
public:
	CW32D(void);
	// TODO: add your methods here.
};

extern W32D_API int nW32D;

W32D_API int fnW32D(void);
W32D_API int GetInt();