
// 3.27-3View.cpp : CMy3273View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.27-3.h"
#endif

#include "3.27-3Doc.h"
#include "3.27-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3273View

IMPLEMENT_DYNCREATE(CMy3273View, CView)

BEGIN_MESSAGE_MAP(CMy3273View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy3273View ����/����

CMy3273View::CMy3273View()
{
	// TODO:  �ڴ˴���ӹ������

	set = true;
	N = 1;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);
	}

}

CMy3273View::~CMy3273View()
{
}

BOOL CMy3273View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3273View ����

void CMy3273View::OnDraw(CDC* pDC)
{
	CMy3273Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		for (int i = 0; i < N; i++)\
		{
			SetTimer(i, 10,NULL);
			set = false;
		}
		
	}
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���

	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
}


// CMy3273View ��ӡ

BOOL CMy3273View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3273View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3273View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy3273View ���

#ifdef _DEBUG
void CMy3273View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3273View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3273Doc* CMy3273View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3273Doc)));
	return (CMy3273Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3273View ��Ϣ�������


void CMy3273View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	int i = nIDEvent;
	CRect rectDlg;
	GetClientRect(rectDlg);//��ô���Ĵ�С
	if (rectDlg.Height() == cr[i].bottom)
		m = 0;
	if (cr[i].top == 0)
		m = 1;
	if (m == 0)
	{
		cr[i].top -= 1;
		cr[i].bottom -= 1;
	}
	if (m==1)
	{
		cr[i].top += 1;
		cr[i].bottom += 1;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
