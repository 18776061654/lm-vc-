
// 414-2-3.h : 414-2-3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy41423App:
// �йش����ʵ�֣������ 414-2-3.cpp
//

class CMy41423App : public CWinAppEx
{
public:
	CMy41423App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy41423App theApp;
