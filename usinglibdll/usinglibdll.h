
// usinglibdll.h : usinglibdll Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CusinglibdllApp:
// �йش����ʵ�֣������ usinglibdll.cpp
//

class CusinglibdllApp : public CWinAppEx
{
public:
	CusinglibdllApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CusinglibdllApp theApp;