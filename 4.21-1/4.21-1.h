
// 4.21-1.h : 4.21-1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy4211App:
// �йش����ʵ�֣������ 4.21-1.cpp
//

class CMy4211App : public CWinAppEx
{
public:
	CMy4211App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy4211App theApp;
