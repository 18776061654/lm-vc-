
// 3.10-1View.cpp : CMy3101View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.10-1.h"
#endif

#include "3.10-1Doc.h"
#include "3.10-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3101View

IMPLEMENT_DYNCREATE(CMy3101View, CView)

BEGIN_MESSAGE_MAP(CMy3101View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy3101View ����/����

CMy3101View::CMy3101View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy3101View::~CMy3101View()
{
}

BOOL CMy3101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3101View ����

void CMy3101View::OnDraw(CDC* /*pDC*/)
{
	CMy3101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy3101View ��ӡ

BOOL CMy3101View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3101View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3101View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy3101View ���

#ifdef _DEBUG
void CMy3101View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3101Doc* CMy3101View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3101Doc)));
	return (CMy3101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3101View ��Ϣ�������


void CMy3101View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CString s;
	s = _T("������ڱ�����");
	CClientDC dc(this);              //����һ������
	dc.TextOutW(100, 200, s);           //���s

	CView::OnLButtonDown(nFlags, point);
}


void CMy3101View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// TODO: Add your message handler code here and/or call default
	CString s;
	s = _T("������ڱ�̧��");
	CClientDC dc(this);              //����һ������
	dc.TextOutW(100, 200, s);           //���s
	CView::OnLButtonUp(nFlags, point);
}
