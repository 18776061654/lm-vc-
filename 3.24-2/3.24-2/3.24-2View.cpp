
// 3.24-2View.cpp : CMy3242View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.24-2.h"
#endif

#include "3.24-2Doc.h"
#include "3.24-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3242View

IMPLEMENT_DYNCREATE(CMy3242View, CView)

BEGIN_MESSAGE_MAP(CMy3242View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy3242View ����/����

CMy3242View::CMy3242View()
{
	// TODO:  �ڴ˴���ӹ������
	BITMAP BM;
	m_bitmap.LoadBitmap(IDB_BITMAP1);
	m_bitmap.GetBitmap(&BM);
	width = BM.bmWidth;
	height = BM.bmHeight;
}

CMy3242View::~CMy3242View()
{
}

BOOL CMy3242View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3242View ����

void CMy3242View::OnDraw(CDC* pDC)
{
	CMy3242Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC memdc;
	memdc.CreateCompatibleDC(NULL);
	memdc.SelectObject(m_bitmap);
	pDC->BitBlt(0, 0, width, height, &memdc,0,0,SRCCOPY);
}


// CMy3242View ��ӡ

BOOL CMy3242View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3242View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3242View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy3242View ���

#ifdef _DEBUG
void CMy3242View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3242View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3242Doc* CMy3242View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3242Doc)));
	return (CMy3242Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3242View ��Ϣ�������
