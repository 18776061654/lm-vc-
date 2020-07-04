
// 综合实验View.cpp : C综合实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验.h"
#endif

#include "综合实验Set.h"
#include "综合实验Doc.h"
#include "综合实验View.h"
#include "pic.h"
#include "zj.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验View

IMPLEMENT_DYNCREATE(C综合实验View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合实验View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合实验View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合实验View::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &C综合实验View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C综合实验View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C综合实验View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C综合实验View::OnBnClickedButton4)
END_MESSAGE_MAP()

// C综合实验View 构造/析构

C综合实验View::C综合实验View()
	: CRecordView(C综合实验View::IDD)
	, id(_T(""))
	, name(_T(""))
	, xuehao(_T(""))
	, xiangce(_T(""))
	, zye(_T(""))
	, sex(_T(""))
	, year(_T(""))
	, phone(_T(""))
	, home(_T(""))
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码
	path = _T("D:\\Program Files (x86)\\JI\\");
}

C综合实验View::~C综合实验View()
{
}

void C综合实验View::DoDataExchange(CDataExchange* pDX)
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
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_5);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->m_6);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->m_7);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->m_8);
}

BOOL C综合实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验View 打印

BOOL C综合实验View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C综合实验View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void C综合实验View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// C综合实验View 诊断
CString  s;
#ifdef _DEBUG
void C综合实验View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验Doc* C综合实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验Doc)));
	return (C综合实验Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验View 数据库支持
CRecordset* C综合实验View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验View 消息处理程序


void C综合实验View::OnRecordFirst()
{
	// TODO: Add your command handler code here
	m_pSet->MoveFirst();
	UpdateData(false);
	
}


void C综合实验View::OnRecordPrev()
{
	// TODO: Add your command handler code here
	m_pSet->MovePrev();
	if (m_pSet->IsEOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	
}


void C综合实验View::OnRecordNext()
{
	// TODO: Add your command handler code here
	m_pSet->MoveNext();
	UpdateData(false);
	
}


void C综合实验View::OnRecordLast()
{
	// TODO: Add your command handler code here
	m_pSet->MoveLast();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}

void C综合实验View::draw_pic(CString s)
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


void C综合实验View::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: Add your specialized code here and/or call the base class
	
	CRecordView::OnPrint(pDC, pInfo);
}


void C综合实验View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CRecordView::OnPaint() for painting messages
	
	GetDlgItemText(IDC_EDIT4, s);
	draw_pic(s);
}


void C综合实验View::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	pic pi;
	pi.s = s;
	int r = pi.DoModal();
}


void C综合实验View::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
}


void C综合实验View::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	zj z;
	int r = z.DoModal();
	if (r == IDOK)
	{
		CString one = z.one;
		m_pSet->AddNew();
		m_pSet->m_1 = one;
		m_pSet->Update();
		UpdateData(false);
	}
}


void C综合实验View::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	zj z;
	int r = z.DoModal();
	if (r == IDOK)
	{
		CString one = z.one;
		m_pSet->Edit();
		m_pSet->m_1 = one;
		m_pSet->Update();
		UpdateData(false);
	}
}
