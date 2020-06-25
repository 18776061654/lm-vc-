// mypi.cpp : implementation file
//

#include "stdafx.h"
#include "4.20-1.h"
#include "mypi.h"
#include "afxdialogex.h"


// mypi dialog

IMPLEMENT_DYNAMIC(mypi, CDialogEx)

mypi::mypi(CWnd* pParent /*=NULL*/)
	: CDialogEx(mypi::IDD, pParent)
{

}

mypi::~mypi()
{
}

void mypi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(mypi, CDialogEx)
END_MESSAGE_MAP()


// mypi message handlers
