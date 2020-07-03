
// 5.4View.cpp : CMy54View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "5.4.h"
#endif

#include "5.4Set.h"
#include "5.4Doc.h"
#include "5.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy54View

IMPLEMENT_DYNCREATE(CMy54View, CRecordView)

BEGIN_MESSAGE_MAP(CMy54View, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy54View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMy54View ����/����

CMy54View::CMy54View()
	: CRecordView(CMy54View::IDD)
	, ID(0)
	, NAME(_T(""))
	, XUEHAO(_T(""))
	, PHONE(_T(""))
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

}

CMy54View::~CMy54View()
{
}

void CMy54View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
}

BOOL CMy54View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMy54View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My54Set;
	CRecordView::OnInitialUpdate();

}


// CMy54View ��ӡ

BOOL CMy54View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy54View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy54View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy54View ���

#ifdef _DEBUG
void CMy54View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy54View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy54Doc* CMy54View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy54Doc)));
	return (CMy54Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy54View ���ݿ�֧��
CRecordset* CMy54View::OnGetRecordset()
{
	return m_pSet;
}



// CMy54View ��Ϣ�������





void CMy54View::draw_pic(CString s)
{
	CImage image;
	image.Load(s);
	int w, h, sx, sy;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_radio = 1.0*rect.Width() / rect.Height();
	float image_radio = 1.0*image.GetWidth() / image.GetHeight();
	if (rect_radio > image_radio)
	{
		h = rect.Height();
		w = image_radio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / image_radio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	image.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void CMy54View::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString s;
	m_pSet->GetFieldValue(short(3), s);
	draw_pic(s);
}