
// 4.14-2-2.h : 4.14-2-2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy41422App:
// �йش����ʵ�֣������ 4.14-2-2.cpp
//

class CMy41422App : public CWinApp
{
public:
	CMy41422App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy41422App theApp;
