
// 4.7-4View.cpp : CMy474View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "4.7-4.h"
#endif

#include "4.7-4Doc.h"
#include "4.7-4View.h"
#include"mydialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy474View

IMPLEMENT_DYNCREATE(CMy474View, CView)

BEGIN_MESSAGE_MAP(CMy474View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMy474View::On32771)
END_MESSAGE_MAP()

// CMy474View ����/����

CMy474View::CMy474View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy474View::~CMy474View()
{
}

BOOL CMy474View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy474View ����

void CMy474View::OnDraw(CDC* /*pDC*/)
{
	CMy474Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy474View ��ӡ

BOOL CMy474View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy474View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy474View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy474View ���

#ifdef _DEBUG
void CMy474View::AssertValid() const
{
	CView::AssertValid();
}

void CMy474View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy474Doc* CMy474View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy474Doc)));
	return (CMy474Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy474View ��Ϣ�������


void CMy474View::On32771()
{
	// TODO: Add your command handler code here
	mydialog dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}
