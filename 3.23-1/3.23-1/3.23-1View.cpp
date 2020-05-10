
// 3.23-1View.cpp : CMy3231View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.23-1.h"
#endif

#include "3.23-1Doc.h"
#include "3.23-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3231View

IMPLEMENT_DYNCREATE(CMy3231View, CView)

BEGIN_MESSAGE_MAP(CMy3231View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_COMMAND(ID_32771, &CMy3231View::On32771)
END_MESSAGE_MAP()

// CMy3231View ����/����

CMy3231View::CMy3231View()
{
	// TODO:  �ڴ˴���ӹ������
	ca.SetSize(256);
	n = 0;
	set = true;
}

CMy3231View::~CMy3231View()
{
}

BOOL CMy3231View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3231View ����

void CMy3231View::OnDraw(CDC* pDC)
{
	CMy3231Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect rectDlg;
	GetClientRect(rectDlg);
	CRect cr(rectDlg.Width() / 2 - n, rectDlg.Height() / 2 - n, rectDlg.Width() / 2 + n, rectDlg.Height() / 2 + n);
	n = n + 10;
	ca.Add(cr);
	pDC->SelectStockObject(NULL_BRUSH);
	for (int i = 0; i < ca.GetSize(); i++)
	{
		pDC->Ellipse(ca.GetAt(i));
	}
	
}


// CMy3231View ��ӡ

BOOL CMy3231View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3231View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3231View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy3231View ���

#ifdef _DEBUG
void CMy3231View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3231View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3231Doc* CMy3231View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3231Doc)));
	return (CMy3231Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3231View ��Ϣ�������


void CMy3231View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy3231View::On32771()
{
	// TODO: Add your command handler code here
	if (set)
	{
		SetTimer(0, 1000, NULL);
		set = false;
	}
	
}
