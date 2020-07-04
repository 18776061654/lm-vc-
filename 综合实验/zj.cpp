// zj.cpp : implementation file
//

#include "stdafx.h"
#include "×ÛºÏÊµÑé.h"
#include "zj.h"
#include "afxdialogex.h"


// zj dialog

IMPLEMENT_DYNAMIC(zj, CDialogEx)

zj::zj(CWnd* pParent /*=NULL*/)
	: CDialogEx(zj::IDD, pParent)
	, one(_T(""))
{

}

zj::~zj()
{
}

void zj::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, one);
}


BEGIN_MESSAGE_MAP(zj, CDialogEx)
END_MESSAGE_MAP()


// zj message handlers
