
// 04.07.h : main header file for the 04.07 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy0407App:
// See 04.07.cpp for the implementation of this class
//

class CMy0407App : public CWinApp
{
public:
	CMy0407App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0407App theApp;
