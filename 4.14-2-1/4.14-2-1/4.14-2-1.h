
// 4.14-2-1.h : 4.14-2-1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy41421App:
// �йش����ʵ�֣������ 4.14-2-1.cpp
//

class CMy41421App : public CWinApp
{
public:
	CMy41421App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy41421App theApp;
