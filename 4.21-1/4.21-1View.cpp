
// 4.21-1View.cpp : CMy4211View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "4.21-1.h"
#endif
#include "mydlg.h"
#include "4.21-1Doc.h"
#include "4.21-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4211View

IMPLEMENT_DYNCREATE(CMy4211View, CView)

BEGIN_MESSAGE_MAP(CMy4211View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMy4211View::On32771)
END_MESSAGE_MAP()

// CMy4211View ����/����

CMy4211View::CMy4211View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy4211View::~CMy4211View()
{
}

BOOL CMy4211View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy4211View ����

void CMy4211View::OnDraw(CDC* /*pDC*/)
{
	CMy4211Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy4211View ��ӡ

BOOL CMy4211View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy4211View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy4211View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy4211View ���

#ifdef _DEBUG
void CMy4211View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4211View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4211Doc* CMy4211View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4211Doc)));
	return (CMy4211Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4211View ��Ϣ�������


void CMy4211View::On32771()
{
	// TODO: Add your command handler code here
	CMy4211Doc* pDoc = GetDocument();
	mydlg dlg;
	for (int i = 0; i < 10;i++)
	dlg.a[i] = pDoc->a[i];
	int r = dlg.DoModal();


}
