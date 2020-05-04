
// 3.16View.cpp : CMy316View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.16.h"
#endif

#include "3.16Doc.h"
#include "3.16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy316View

IMPLEMENT_DYNCREATE(CMy316View, CView)

BEGIN_MESSAGE_MAP(CMy316View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy316View ����/����

CMy316View::CMy316View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy316View::~CMy316View()
{
}

BOOL CMy316View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy316View ����

void CMy316View::OnDraw(CDC* pDC)
{
	CMy316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->cr);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy316View ��ӡ

BOOL CMy316View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy316View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy316View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy316View ���

#ifdef _DEBUG
void CMy316View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316Doc* CMy316View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316Doc)));
	return (CMy316Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316View ��Ϣ�������


void CMy316View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CMy316Doc* pDoc = GetDocument();
	pDoc->cr.left = point.x;
	pDoc->cr.top = point.y;


	CView::OnLButtonDown(nFlags, point);
}


void CMy316View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy316Doc* pDoc = GetDocument();
	pDoc->cr.right = point.x;
	pDoc->cr.bottom = point.y;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonUp(nFlags, point);
}


void CMy316View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CString s;
	s.Format(_T("��굱ǰ���꣺(%d,%d)"), point.x, point.y); //������ֵת����s
	CClientDC dc(this);              //����һ������
	dc.TextOutW(100, 200, s);           //���s


	CView::OnMouseMove(nFlags, point);
}
