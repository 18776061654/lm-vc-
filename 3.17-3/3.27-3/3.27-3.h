
// 3.27-3.h : 3.27-3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy3273App:
// �йش����ʵ�֣������ 3.27-3.cpp
//

class CMy3273App : public CWinAppEx
{
public:
	CMy3273App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy3273App theApp;
