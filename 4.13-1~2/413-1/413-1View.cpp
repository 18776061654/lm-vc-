
// 413-1View.cpp : CMy4131View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "413-1.h"
#endif
#include "mydialog.h"
#include "413-1Doc.h"
#include "413-1View.h"
#include "mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4131View

IMPLEMENT_DYNCREATE(CMy4131View, CView)

BEGIN_MESSAGE_MAP(CMy4131View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32771, &CMy4131View::On32771)
END_MESSAGE_MAP()

// CMy4131View ����/����

CMy4131View::CMy4131View()
{
	// TODO:  �ڴ˴���ӹ������
	s1 = "";
}

CMy4131View::~CMy4131View()
{
}

BOOL CMy4131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy4131View ����

void CMy4131View::OnDraw(CDC* /*pDC*/)
{
	CMy4131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy4131View ��ӡ

BOOL CMy4131View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy4131View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy4131View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy4131View ���

#ifdef _DEBUG
void CMy4131View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4131Doc* CMy4131View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4131Doc)));
	return (CMy4131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4131View ��Ϣ�������


void CMy4131View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	mydlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		 s1 = dlg.s;
		GetDC()->TextOutW(200, 100, s1);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy4131View::On32771()
{
	// TODO: Add your command handler code here
	mydialog mydlg;
	mydlg.s2 = s1;
	int r = mydlg.DoModal();
	if (r == IDOK)
	{
		
	}
	
}

