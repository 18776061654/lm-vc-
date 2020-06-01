
// 414-2-3View.cpp : CMy41423View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "414-2-3.h"
#endif

#include "414-2-3Doc.h"
#include "414-2-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy41423View

IMPLEMENT_DYNCREATE(CMy41423View, CView)

BEGIN_MESSAGE_MAP(CMy41423View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy41423View ����/����

CMy41423View::CMy41423View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy41423View::~CMy41423View()
{
}

BOOL CMy41423View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy41423View ����

void CMy41423View::OnDraw(CDC* pDC)
{
	CMy41423Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	
	pDC->Ellipse(pDoc->cr);

	

}


// CMy41423View ��ӡ

BOOL CMy41423View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy41423View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy41423View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy41423View ���

#ifdef _DEBUG
void CMy41423View::AssertValid() const
{
	CView::AssertValid();
}

void CMy41423View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy41423Doc* CMy41423View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy41423Doc)));
	return (CMy41423Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy41423View ��Ϣ�������


void CMy41423View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (point.x >= 200 && point.x < 500 && point.y >= 200 && point.y < 300)
	{
		CMy41423Doc* pDoc = GetDocument();
		CDC * dc = GetDC();
		CPen * pOldPen = NULL;
		CPen pen;
		pen.CreatePen(PS_DASH, 1, RGB(0, 255, 0));
		pOldPen = dc->SelectObject(&pen);
		CBrush * pOldBrush = NULL;
		CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		pOldBrush = dc->SelectObject(pBrush);
		dc->Rectangle(&pDoc->cr);
		dc->SelectObject(pOldPen);
		pen.DeleteObject();
	}
	CView::OnLButtonDown(nFlags, point);
}
