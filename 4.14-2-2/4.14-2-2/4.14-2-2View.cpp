
// 4.14-2-2View.cpp : CMy41422View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "4.14-2-2.h"
#endif

#include "4.14-2-2Doc.h"
#include "4.14-2-2View.h"
#include "mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy41422View

IMPLEMENT_DYNCREATE(CMy41422View, CView)

BEGIN_MESSAGE_MAP(CMy41422View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy41422View::OnBnClickedButton1)
	ON_COMMAND(ID_32771, &CMy41422View::On32771)
END_MESSAGE_MAP()

// CMy41422View ����/����

CMy41422View::CMy41422View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy41422View::~CMy41422View()
{
}

BOOL CMy41422View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy41422View ����

void CMy41422View::OnDraw(CDC* pDC)
{
	CMy41422Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(pDoc->cr);
}


// CMy41422View ��ӡ

BOOL CMy41422View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy41422View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy41422View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy41422View ���

#ifdef _DEBUG
void CMy41422View::AssertValid() const
{
	CView::AssertValid();
}

void CMy41422View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy41422Doc* CMy41422View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy41422Doc)));
	return (CMy41422Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy41422View ��Ϣ�������


void CMy41422View::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	

	

}


void CMy41422View::On32771()
{
	// TODO: Add your command handler code here
	mydlg dlg;
	CMy41422Doc* pDoc = GetDocument();
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		pDoc->cr.left = dlg.left;
		pDoc->cr.right = dlg.right;
		pDoc->cr.top = dlg.top;
		pDoc->cr.bottom = dlg.bottom;
		Invalidate();
	}
}
