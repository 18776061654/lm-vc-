
// starView.cpp : CstarView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "star.h"
#endif

#include "starDoc.h"
#include "starView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "w32.h"

// CstarView

IMPLEMENT_DYNCREATE(CstarView, CView)

BEGIN_MESSAGE_MAP(CstarView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CstarView ����/����

CstarView::CstarView()
{
	// TODO:  �ڴ˴���ӹ������

}

CstarView::~CstarView()
{
}

BOOL CstarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CstarView ����

void CstarView::OnDraw(CDC* pDC)
{
	CstarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
    s.Format(_T("%d"),factorial(5));
	pDC->TextOutW(200,200,s);
}


// CstarView ��ӡ

BOOL CstarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CstarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CstarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CstarView ���

#ifdef _DEBUG
void CstarView::AssertValid() const
{
	CView::AssertValid();
}

void CstarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CstarDoc* CstarView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CstarDoc)));
	return (CstarDoc*)m_pDocument;
}
#endif //_DEBUG


// CstarView ��Ϣ�������
