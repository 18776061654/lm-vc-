
// 3.17-1View.cpp : CMy3171View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.17-1.h"
#endif

#include "3.17-1Doc.h"
#include "3.17-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3171View

IMPLEMENT_DYNCREATE(CMy3171View, CView)

BEGIN_MESSAGE_MAP(CMy3171View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy3171View ����/����

CMy3171View::CMy3171View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy3171View::~CMy3171View()
{
}

BOOL CMy3171View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3171View ����

void CMy3171View::OnDraw(CDC* /*pDC*/)
{
	CMy3171Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy3171View ��ӡ

BOOL CMy3171View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3171View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3171View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy3171View ���

#ifdef _DEBUG
void CMy3171View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3171View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3171Doc* CMy3171View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3171Doc)));
	return (CMy3171Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3171View ��Ϣ�������


void CMy3171View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy3171Doc* pDoc = GetDocument();
	CClientDC dc(this);              //����һ������
	CString s;
	
	
	if (nFlags)
	{
		pDoc->count++;
		s.Format(_T("mousemove�����ˣ�%d ��"), pDoc->count);
		dc.TextOutW(100, 200, s);           //���s

	}

	CView::OnMouseMove(nFlags, point);
}


void CMy3171View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy3171Doc* pDoc = GetDocument();
	pDoc->x1 = point.x;
	CView::OnLButtonDown(nFlags, point);
}


void CMy3171View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy3171Doc* pDoc = GetDocument();
	CClientDC dc(this);              //����һ������
	CString s;
	pDoc->x2 = point.x;
	pDoc->count = 0;
	s.Format(_T("�����ƶ��ˣ�%d ����"), pDoc->x2 -pDoc->x1);
	dc.TextOutW(100, 300, s);           //���s
	CView::OnLButtonUp(nFlags, point);
}
