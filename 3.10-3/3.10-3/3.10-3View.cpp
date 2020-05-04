
// 3.10-3View.cpp : CMy3103View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.10-3.h"
#endif

#include "3.10-3Doc.h"
#include "3.10-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3103View

IMPLEMENT_DYNCREATE(CMy3103View, CView)

BEGIN_MESSAGE_MAP(CMy3103View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy3103View ����/����

CMy3103View::CMy3103View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy3103View::~CMy3103View()
{
}

BOOL CMy3103View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3103View ����

void CMy3103View::OnDraw(CDC* pDC)
{
	CMy3103Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect ca(200, 70, 500, 300);	CRect cb(800, 70, 1200, 300);CRect cc(400, 400, 800, 600);
	pDC->Rectangle(ca); pDC->Rectangle(cb); pDC->Rectangle(cc);
}


// CMy3103View ��ӡ

BOOL CMy3103View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3103View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3103View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy3103View ���

#ifdef _DEBUG
void CMy3103View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3103View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3103Doc* CMy3103View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3103Doc)));
	return (CMy3103Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3103View ��Ϣ�������


void CMy3103View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);              //����һ������
	CMy3103Doc* pDoc = GetDocument();
	CString s1, s2, s3,s4,s5;
	s4 = _T("�����Ч");
	s5 = _T("�����Ч");
	if ((point.x>200) && (point.x<500) && (point.y>70) && (point.y<300))
	{
		pDoc->a = rand()*((100 - 1) / 100+1);
		s1.Format(_T("a=%d"), pDoc->a);
		dc.TextOutW(400, 175, s1);
		dc.TextOutW(10, 20, s5);

	}
	else if ((point.x>800) && (point.x <1200) && (point.y>70) && (point.y < 300))
	{
		pDoc->b = rand()*((100 - 1) / 100 + 1);
		s2.Format(_T("b=%d"), pDoc->b);
		dc.TextOutW(1000, 175, s2);
		dc.TextOutW(10, 20, s5);
	}
	
	else if((point.x>400) && (point.x < 800) && (point.y>400) && (point.y < 600))
	{
		pDoc->c = pDoc->a + pDoc->b;
		s3.Format(_T("a+b=%d"), pDoc->c);
		dc.TextOutW(600, 500, s3);
		dc.TextOutW(10, 20, s5);
	}
	else
	{
		dc.TextOutW(10, 20, s4);
	}
		CView::OnLButtonDown(nFlags, point);
}
