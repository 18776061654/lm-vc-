
// 3.3-2.h : main header file for the 3.3-2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy332App:
// See 3.3-2.cpp for the implementation of this class
//

class CMy332App : public CWinAppEx
{
public:
	CMy332App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy332App theApp;
