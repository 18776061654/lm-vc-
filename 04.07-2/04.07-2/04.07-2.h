
// 04.07-2.h : 04.07-2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy04072App:
// �йش����ʵ�֣������ 04.07-2.cpp
//

class CMy04072App : public CWinAppEx
{
public:
	CMy04072App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy04072App theApp;
