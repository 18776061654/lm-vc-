
// tuxingView.cpp : CtuxingView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "tuxing.h"
#endif

#include "tuxingDoc.h"
#include "tuxingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtuxingView

IMPLEMENT_DYNCREATE(CtuxingView, CView)

BEGIN_MESSAGE_MAP(CtuxingView, CView)
END_MESSAGE_MAP()

// CtuxingView ����/����

CtuxingView::CtuxingView()
{
	// TODO:  �ڴ˴���ӹ������

}

CtuxingView::~CtuxingView()
{
}

BOOL CtuxingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CtuxingView ����

void CtuxingView::OnDraw(CDC* /*pDC*/)
{
	CtuxingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s,c;
	int a = 20;
	s = _T("���Ǵ�˧��!!");
	c.Format(_T("%d"), a);
	CClientDC dc(this);              //����һ������
	dc.TextOutW(100, 200, s);           //���s
	dc.TextOutW(400, 200, c);
	



}


// CtuxingView ���

#ifdef _DEBUG
void CtuxingView::AssertValid() const
{
	CView::AssertValid();
}

void CtuxingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtuxingDoc* CtuxingView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtuxingDoc)));
	return (CtuxingDoc*)m_pDocument;
}
#endif //_DEBUG


// CtuxingView ��Ϣ�������
