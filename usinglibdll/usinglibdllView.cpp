
// usinglibdllView.cpp : CusinglibdllView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "usinglibdll.h"
#endif

#include "usinglibdllDoc.h"
#include "usinglibdllView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"win32.h"
#include"W32D\W32D.h"
// CusinglibdllView

IMPLEMENT_DYNCREATE(CusinglibdllView, CView)

BEGIN_MESSAGE_MAP(CusinglibdllView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CusinglibdllView ����/����

CusinglibdllView::CusinglibdllView()
{
	// TODO:  �ڴ˴���ӹ������

}

CusinglibdllView::~CusinglibdllView()
{
}

BOOL CusinglibdllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CusinglibdllView ����

void CusinglibdllView::OnDraw(CDC* pDC)
{
	CusinglibdllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	s = CString(pchar());
	pDC->TextOutW(200, 200, s);

	CString ss;
	ss.Format(_T("%d,���Ƕ�̬����idֵ"), GetInt());
	pDC->TextOutW(200, 400, ss);
}


// CusinglibdllView ��ӡ

BOOL CusinglibdllView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CusinglibdllView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CusinglibdllView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CusinglibdllView ���

#ifdef _DEBUG
void CusinglibdllView::AssertValid() const
{
	CView::AssertValid();
}

void CusinglibdllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CusinglibdllDoc* CusinglibdllView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CusinglibdllDoc)));
	return (CusinglibdllDoc*)m_pDocument;
}
#endif //_DEBUG


// CusinglibdllView ��Ϣ�������
