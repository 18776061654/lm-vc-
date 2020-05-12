
// 4.7-1View.cpp : CMy471View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "4.7-1.h"
#endif

#include "4.7-1Doc.h"
#include "4.7-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy471View

IMPLEMENT_DYNCREATE(CMy471View, CView)

BEGIN_MESSAGE_MAP(CMy471View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy471View ����/����

CMy471View::CMy471View()
{
	// TODO:  �ڴ˴���ӹ������
	cr.top = 100;
	cr.left = 100;
	cr.right = 400;
	cr.bottom = 400;
	top = 0;
	right = 0;
	left = 0;
	bottom = 0;
	M = 0;
}

CMy471View::~CMy471View()
{
}

BOOL CMy471View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy471View ����

void CMy471View::OnDraw(CDC* pDC)
{
	CMy471Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���

	pDC->Rectangle(cr);
}


// CMy471View ��ӡ

BOOL CMy471View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy471View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy471View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy471View ���

#ifdef _DEBUG
void CMy471View::AssertValid() const
{
	CView::AssertValid();
}

void CMy471View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy471Doc* CMy471View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy471Doc)));
	return (CMy471Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy471View ��Ϣ�������


void CMy471View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (point.x >= cr.left&&point.x <= cr.right&&point.y >= cr.top&&point.y <= cr.bottom)
	{
		left = point.x - cr.left;
		right = cr.right - point.x;
		top = point.y - cr.top;
		bottom = cr.bottom - point.y;
		M = 1;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy471View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (M == 1)
	{
		cr.left = point.x - left;
		cr.right = point.x + right;
		cr.top = point.y - top;
		cr.bottom = point.y + bottom;
		Invalidate();
		M = 0;
	}
	CView::OnLButtonUp(nFlags, point);
}
