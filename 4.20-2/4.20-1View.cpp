
// 4.20-1View.cpp : CMy4201View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "4.20-1.h"
#endif

#include "4.20-1Doc.h"
#include "4.20-1View.h"
#include<string>
#include<iostream>
#include<fstream>
#include"mypi.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4201View

IMPLEMENT_DYNCREATE(CMy4201View, CView)

BEGIN_MESSAGE_MAP(CMy4201View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMy4201View::OnFileOpen)
	ON_COMMAND(ID_32771, &CMy4201View::On32771)
END_MESSAGE_MAP()

// CMy4201View ����/����

CMy4201View::CMy4201View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy4201View::~CMy4201View()
{
}

BOOL CMy4201View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy4201View ����

void CMy4201View::OnDraw(CDC* /*pDC*/)
{
	CMy4201Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy4201View ��ӡ

BOOL CMy4201View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy4201View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy4201View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy4201View ���

#ifdef _DEBUG
void CMy4201View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4201View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4201Doc* CMy4201View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4201Doc)));
	return (CMy4201Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4201View ��Ϣ�������


void CMy4201View::OnFileOpen()
{
	// TODO: Add your command handler code here
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		CStdioFile File;
		File.Open(_T("abc.txt"), CFile::modeReadWrite | CFile::modeNoTruncate | CFile::modeCreate);
		File.WriteString(filename);
		
	}
}


void CMy4201View::On32771()
{
	// TODO: Add your command handler code here
	CStdioFile File;
	CString str;
	File.Open(_T("abc.txt"), CFile::modeReadWrite | CFile::modeNoTruncate | CFile::modeCreate);
	File.ReadString(str);
	CClientDC dc(this);
	dc.TextOutW(200, 600, str);
	mypi dlg;
	int r = dlg.DoModal();

}
