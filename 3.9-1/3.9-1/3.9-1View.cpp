
// 3.9-1View.cpp : CMy391View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.9-1.h"
#endif

#include "3.9-1Doc.h"
#include "3.9-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy391View

IMPLEMENT_DYNCREATE(CMy391View, CView)

BEGIN_MESSAGE_MAP(CMy391View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy391View ����/����

CMy391View::CMy391View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy391View::~CMy391View()
{
}

BOOL CMy391View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy391View ����

void CMy391View::OnDraw(CDC* /*pDC*/)
{
	CMy391Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���

}


// CMy391View ��ӡ

BOOL CMy391View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy391View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy391View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy391View ���

#ifdef _DEBUG
void CMy391View::AssertValid() const
{
	CView::AssertValid();
}

void CMy391View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy391Doc* CMy391View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy391Doc)));
	return (CMy391Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy391View ��Ϣ�������


void CMy391View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	CRect rc;
	GetClientRect(&rc);
	int nWidth = rc.Width();
	int nheight = rc.Height();
	if (nWidth>nheight)
		dc.Ellipse(0, 0, nheight, nheight);
	else
		dc.Ellipse(0, 0, nWidth, nWidth);

	CView::OnLButtonDown(nFlags, point);
}
