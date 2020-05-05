
// 3.17-2View.cpp : CMy3172View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.17-2.h"
#endif

#include "3.17-2Doc.h"
#include "3.17-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3172View

IMPLEMENT_DYNCREATE(CMy3172View, CView)

BEGIN_MESSAGE_MAP(CMy3172View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy3172View ����/����

CMy3172View::CMy3172View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy3172View::~CMy3172View()
{
}

BOOL CMy3172View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3172View ����

void CMy3172View::OnDraw(CDC* pDC)
{
	CMy3172Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���


	pDC->Rectangle(pDoc->cr);
}


// CMy3172View ��ӡ

BOOL CMy3172View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3172View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3172View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy3172View ���

#ifdef _DEBUG
void CMy3172View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3172View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3172Doc* CMy3172View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3172Doc)));
	return (CMy3172Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3172View ��Ϣ�������


void CMy3172View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CMy3172Doc* pDoc = GetDocument();

	switch (nChar)
	{
	case VK_LEFT:{
		pDoc->cr.left -= 3;
		pDoc->cr.right -= 3;
	}break;
	case VK_RIGHT:{
		pDoc->cr.left += 3;
		pDoc->cr.right += 3;
	}break;

	case VK_UP:{
		pDoc->cr.top -= 3;
		pDoc->cr.bottom -= 3;
	}break;

	case VK_DOWN:{
		pDoc->cr.top += 3;
		pDoc->cr.bottom += 3;
	}break;

	case VK_HOME:{
		pDoc->cr.top -= 3;
		pDoc->cr.left -= 3;
	}break;
	case VK_END:{
		pDoc->cr.bottom += 3;
		pDoc->cr.right += 3;
	}break;
	}
	InvalidateRect(NULL, TRUE);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy3172View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy3172Doc* pDoc = GetDocument();
	pDoc->cr.top = 200; pDoc->cr.left = 500; pDoc->cr.bottom = 300; pDoc->cr.right = 600;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
