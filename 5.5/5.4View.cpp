
// 5.4View.cpp : CMy54View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy54View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMy54View 构造/析构

CMy54View::CMy54View()
	: CRecordView(CMy54View::IDD)
	, ID(0)
	, NAME(_T(""))
	, XUEHAO(_T(""))
	, PHONE(_T(""))
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码

}

CMy54View::~CMy54View()
{
}

void CMy54View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
}

BOOL CMy54View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMy54View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My54Set;
	CRecordView::OnInitialUpdate();

}


// CMy54View 打印

BOOL CMy54View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy54View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy54View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy54View 诊断

#ifdef _DEBUG
void CMy54View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy54View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy54Doc* CMy54View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy54Doc)));
	return (CMy54Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy54View 数据库支持
CRecordset* CMy54View::OnGetRecordset()
{
	return m_pSet;
}



// CMy54View 消息处理程序





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