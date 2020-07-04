// pic.cpp : implementation file
//

#include "stdafx.h"
#include "×ÛºÏÊµÑé.h"
#include "pic.h"
#include "afxdialogex.h"


// pic dialog

IMPLEMENT_DYNAMIC(pic, CDialogEx)

pic::pic(CWnd* pParent /*=NULL*/)
	: CDialogEx(pic::IDD, pParent)
{

}

pic::~pic()
{
}

void pic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(pic, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// pic message handlers
void pic::draw_pic(CString s)
{
	CImage image;
	image.Load(s);
	int w, h, sx, sy;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_radio = 1.0*rect.Width() / rect.Height();
	float image_radio = 1.0*image.GetWidth() / image.GetHeight();
	if (rect_radio > image_radio)
	{
		h = rect.Height();
		w = image_radio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / image_radio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	image.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void pic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
	draw_pic(s);
}
