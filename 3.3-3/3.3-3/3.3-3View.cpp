
// 3.3-3View.cpp : CMy333View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.3-3.h"
#endif

#include "3.3-3Doc.h"
#include "3.3-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy333View

IMPLEMENT_DYNCREATE(CMy333View, CView)

BEGIN_MESSAGE_MAP(CMy333View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy333View ����/����

CMy333View::CMy333View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy333View::~CMy333View()
{
}

BOOL CMy333View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy333View ����

void CMy333View::OnDraw(CDC* /*pDC*/)
{
	CMy333Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy333View ��ӡ

BOOL CMy333View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy333View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy333View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy333View ���

#ifdef _DEBUG
void CMy333View::AssertValid() const
{
	CView::AssertValid();
}

void CMy333View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy333Doc* CMy333View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy333Doc)));
	return (CMy333Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy333View ��Ϣ�������


void CMy333View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy333Doc* pDoc = GetDocument();
	pDoc->count = pDoc->count + 1;

	CView::OnLButtonDown(nFlags, point);
}


void CMy333View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default


	CView::OnMButtonDown(nFlags, point);
}


void CMy333View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy333Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	CDC* pDC = GetDC(); 
	pDC->TextOut(20, 20, s);
	CView::OnRButtonDown(nFlags, point);
	
}
