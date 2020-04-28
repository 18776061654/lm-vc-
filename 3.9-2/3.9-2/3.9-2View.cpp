
// 3.9-2View.cpp : CMy392View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.9-2.h"
#endif

#include "3.9-2Doc.h"
#include "3.9-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy392View

IMPLEMENT_DYNCREATE(CMy392View, CView)

BEGIN_MESSAGE_MAP(CMy392View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy392View ����/����

CMy392View::CMy392View()
{
	// TODO:  �ڴ˴���ӹ������
	

}

CMy392View::~CMy392View()
{
}

BOOL CMy392View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy392View ����

void CMy392View::OnDraw(CDC* pDC)
{
	CMy392Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < pDoc->ca.GetSize(); i++){
	
		pDC->Ellipse(pDoc->ca.GetAt(i));
	}

	
}


// CMy392View ��ӡ

BOOL CMy392View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy392View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy392View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy392View ���

#ifdef _DEBUG
void CMy392View::AssertValid() const
{
	CView::AssertValid();
}

void CMy392View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy392Doc* CMy392View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy392Doc)));
	return (CMy392Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy392View ��Ϣ�������


void CMy392View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy392Doc* pDoc = GetDocument();
	int r = rand() % 50 + 5;
	int t = rand() % 50 + 5;
	CRect cr(point.x - r, point.y - t, point.x + r, point.y + t);

	pDoc->ca.Add(cr);
	this->Invalidate();
	
	CView::OnLButtonDown(nFlags, point);
}
