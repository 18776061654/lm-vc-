// mydialog.cpp : implementation file
//

#include "stdafx.h"
#include "04.07.h"
#include "mydialog.h"
#include "afxdialogex.h"


// mydialog dialog

IMPLEMENT_DYNAMIC(mydialog, CDialogEx)

mydialog::mydialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(mydialog::IDD, pParent)
{

}

mydialog::~mydialog()
{
}

void mydialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(mydialog, CDialogEx)
END_MESSAGE_MAP()


// mydialog message handlers
