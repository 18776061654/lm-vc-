
// tuxing.h : tuxing Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CtuxingApp:
// �йش����ʵ�֣������ tuxing.cpp
//

class CtuxingApp : public CWinApp
{
public:
	CtuxingApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CtuxingApp theApp;
