
// 04.07-2View.cpp : CMy04072View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "04.07-2.h"
#endif

#include "04.07-2Doc.h"
#include "04.07-2View.h"
#include "Mydialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04072View

IMPLEMENT_DYNCREATE(CMy04072View, CView)

BEGIN_MESSAGE_MAP(CMy04072View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_change, &CMy04072View::Onchange)
END_MESSAGE_MAP()

// CMy04072View ����/����

CMy04072View::CMy04072View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy04072View::~CMy04072View()
{
}

BOOL CMy04072View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy04072View ����

void CMy04072View::OnDraw(CDC* /*pDC*/)
{
	CMy04072Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy04072View ��ӡ

BOOL CMy04072View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy04072View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy04072View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy04072View ���

#ifdef _DEBUG
void CMy04072View::AssertValid() const
{
	CView::AssertValid();
}

void CMy04072View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04072Doc* CMy04072View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04072Doc)));
	return (CMy04072Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy04072View ��Ϣ�������


void CMy04072View::Onchange()
{
	// TODO: Add your command handler code here
	Mydialog dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}
