
// 4.7-3View.cpp : CMy473View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "4.7-3.h"
#endif

#include "4.7-3Doc.h"
#include "4.7-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy473View

IMPLEMENT_DYNCREATE(CMy473View, CView)

BEGIN_MESSAGE_MAP(CMy473View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy473View ����/����

CMy473View::CMy473View()
{
	// TODO:  �ڴ˴���ӹ������
	cr.top = 300;
	cr.left = 100;
	cr.right = 200;
	cr.bottom = 400;
	set = true;
	m = 0;
}

CMy473View::~CMy473View()
{
}

BOOL CMy473View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy473View ����

void CMy473View::OnDraw(CDC* pDC)
{
	CMy473Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect rectDlg;
	GetClientRect(rectDlg);
	
	if ((cr.right + 10) < rectDlg.Width()&&m==0)
		{
			cr.left += 10;
			cr.right += 10;
		}
	else if ((cr.left - 10) > 0)
	{
		m = 1;
		cr.left -= 10;
		cr.right -= 10;

	}
		if ((cr.left - 10) <= 0)
		{
			m = 0;

		}
	

	pDC->Ellipse(cr);
}


// CMy473View ��ӡ

BOOL CMy473View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy473View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy473View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy473View ���

#ifdef _DEBUG
void CMy473View::AssertValid() const
{
	CView::AssertValid();
}

void CMy473View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy473Doc* CMy473View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy473Doc)));
	return (CMy473Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy473View ��Ϣ�������


void CMy473View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (set)
	{
		SetTimer(0, 100, NULL);
		set = false;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy473View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy473View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(0);
	set = true;
	CView::OnLButtonDblClk(nFlags, point);
}
