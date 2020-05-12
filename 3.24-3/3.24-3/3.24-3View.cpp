
// 3.24-3View.cpp : CMy3243View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.24-3.h"
#endif

#include "3.24-3Doc.h"
#include "3.24-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3243View

IMPLEMENT_DYNCREATE(CMy3243View, CView)

BEGIN_MESSAGE_MAP(CMy3243View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMy3243View::On32771)
	ON_COMMAND(ID_32772, &CMy3243View::On32772)
	ON_COMMAND(ID_32773, &CMy3243View::On32773)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy3243View ����/����

CMy3243View::CMy3243View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy3243View::~CMy3243View()
{
}

BOOL CMy3243View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3243View ����

void CMy3243View::OnDraw(CDC* /*pDC*/)
{
	CMy3243Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy3243View ��ӡ

BOOL CMy3243View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3243View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3243View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy3243View ���

#ifdef _DEBUG
void CMy3243View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3243View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3243Doc* CMy3243View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3243Doc)));
	return (CMy3243Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3243View ��Ϣ�������


void CMy3243View::On32771()
{
	// TODO: Add your command handler code here
	m = 1;
}


void CMy3243View::On32772()
{
	// TODO: Add your command handler code here
	m = 2;
}


void CMy3243View::On32773()
{
	// TODO: Add your command handler code here
	m = 3;
}


void CMy3243View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m == 1 || m == 2 || m == 3)
	{
		n = point;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy3243View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m == 1)
	{

		HDC hdc;
		hdc = ::GetDC(m_hWnd);
		MoveToEx(hdc, n.x, n.y, NULL);
		LineTo(hdc, point.x, point.y);
	}
	if (m == 2)
	{
		CClientDC dc(this);
		dc.Rectangle(CRect(n, point));
	}
	if (m == 3)
	{
		CClientDC dc(this);
		dc.Ellipse(CRect(n, point));
	}

	CView::OnLButtonUp(nFlags, point);
}
