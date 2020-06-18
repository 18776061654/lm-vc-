
// 414-2-4View.cpp : CMy41424View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "414-2-4.h"
#endif

#include "414-2-4Doc.h"
#include "414-2-4View.h"
#include "mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy41424View

IMPLEMENT_DYNCREATE(CMy41424View, CView)

BEGIN_MESSAGE_MAP(CMy41424View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy41424View::OnBnClickedButton1)
	ON_COMMAND(ID_32771, &CMy41424View::On32771)
END_MESSAGE_MAP()

// CMy41424View ����/����

CMy41424View::CMy41424View()
{
	// TODO:  �ڴ˴���ӹ������
	x = 0;
	y = 0;
	z = 0;
}

CMy41424View::~CMy41424View()
{
}

BOOL CMy41424View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy41424View ����

void CMy41424View::OnDraw(CDC* pDC)
{
	CMy41424Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	
	pDC->Ellipse(20, 20, 200, 200);
	if (z != 0)
	{
		CBrush brush(RGB(x, y, z));//�����Լ���Ҫ�����ɫ
		CBrush *oldbrush;
		oldbrush = pDC->SelectObject(&brush);//ѡ�µĻ�ˢ
		pDC->Ellipse(20, 20, 200, 200);
		pDC->SelectObject(oldbrush);//��ԭ���Ļ�ˢѡ��ȥ 
	}
}


// CMy41424View ��ӡ

BOOL CMy41424View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy41424View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy41424View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy41424View ���

#ifdef _DEBUG
void CMy41424View::AssertValid() const
{
	CView::AssertValid();
}

void CMy41424View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy41424Doc* CMy41424View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy41424Doc)));
	return (CMy41424Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy41424View ��Ϣ�������


void CMy41424View::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

}


void CMy41424View::On32771()
{
	// TODO: Add your command handler code here
	mydlg dlg;
	int r = dlg.DoModal();
	x = dlg.x;
	y = dlg.y;
	z = dlg.z;
	if (r == IDOK)
	{
		Invalidate();
	}

}
