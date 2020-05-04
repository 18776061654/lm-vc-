
// 3.10-2View.cpp : CMy3102View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.10-2.h"
#endif

#include "3.10-2Doc.h"
#include "3.10-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3102View

IMPLEMENT_DYNCREATE(CMy3102View, CView)

BEGIN_MESSAGE_MAP(CMy3102View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy3102View ����/����

CMy3102View::CMy3102View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy3102View::~CMy3102View()
{
}

BOOL CMy3102View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3102View ����

void CMy3102View::OnDraw(CDC* /*pDC*/)
{
	CMy3102Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy3102View ��ӡ

BOOL CMy3102View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3102View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3102View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy3102View ���

#ifdef _DEBUG
void CMy3102View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3102View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3102Doc* CMy3102View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3102Doc)));
	return (CMy3102Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3102View ��Ϣ�������


void CMy3102View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy3102Doc* pDoc = GetDocument();
	CString s;
	int c;
	c = pDoc->a + pDoc->b;
	CClientDC dc(this);              //����һ������
	s.Format(_T("A+B=%d"),c);
	dc.TextOutW(100, 200, s);           //���s


	CView::OnLButtonDown(nFlags, point);
}
