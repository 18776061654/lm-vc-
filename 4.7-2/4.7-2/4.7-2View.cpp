
// 4.7-2View.cpp : CMy472View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "4.7-2.h"
#endif

#include "4.7-2Doc.h"
#include "4.7-2View.h"
#include"mydialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy472View

IMPLEMENT_DYNCREATE(CMy472View, CView)

BEGIN_MESSAGE_MAP(CMy472View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMy472View::On32771)
END_MESSAGE_MAP()

// CMy472View ����/����

CMy472View::CMy472View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy472View::~CMy472View()
{
}

BOOL CMy472View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy472View ����

void CMy472View::OnDraw(CDC* /*pDC*/)
{
	CMy472Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy472View ��ӡ

BOOL CMy472View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy472View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy472View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy472View ���

#ifdef _DEBUG
void CMy472View::AssertValid() const
{
	CView::AssertValid();
}

void CMy472View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy472Doc* CMy472View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy472Doc)));
	return (CMy472Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy472View ��Ϣ�������


void CMy472View::On32771()
{
	// TODO: Add your command handler code here
	mydialog dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		
	}
}
