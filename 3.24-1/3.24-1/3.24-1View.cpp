
// 3.24-1View.cpp : CMy3241View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.24-1.h"
#endif

#include "3.24-1Doc.h"
#include "3.24-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3241View

IMPLEMENT_DYNCREATE(CMy3241View, CView)

BEGIN_MESSAGE_MAP(CMy3241View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_NAME_LMNAME, &CMy3241View::OnNameLmname)
END_MESSAGE_MAP()

// CMy3241View ����/����

CMy3241View::CMy3241View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy3241View::~CMy3241View()
{
}

BOOL CMy3241View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3241View ����

void CMy3241View::OnDraw(CDC* /*pDC*/)
{
	CMy3241Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy3241View ��ӡ

BOOL CMy3241View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3241View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3241View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy3241View ���

#ifdef _DEBUG
void CMy3241View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3241View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3241Doc* CMy3241View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3241Doc)));
	return (CMy3241Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3241View ��Ϣ�������


void CMy3241View::OnNameLmname()
{
	// TODO: Add your command handler code here
	CString s = _T("������¬��");
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);

}
