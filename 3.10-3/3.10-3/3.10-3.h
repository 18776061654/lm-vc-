
// 3.10-3.h : 3.10-3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy3103App:
// �йش����ʵ�֣������ 3.10-3.cpp
//

class CMy3103App : public CWinAppEx
{
public:
	CMy3103App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy3103App theApp;
