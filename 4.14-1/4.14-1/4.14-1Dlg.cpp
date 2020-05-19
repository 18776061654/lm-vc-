
// 4.14-1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "4.14-1.h"
#include "4.14-1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy4141Dlg �Ի���



CMy4141Dlg::CMy4141Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy4141Dlg::IDD, pParent)
	, x(0)
	, y(0)
	, z(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy4141Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, z);
}

BEGIN_MESSAGE_MAP(CMy4141Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy4141Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy4141Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMy4141Dlg ��Ϣ�������

BOOL CMy4141Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy4141Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy4141Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy4141Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy4141Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString tempstr;
	GetDlgItem(IDC_BUTTON1)->GetWindowText(tempstr);
	if (tempstr == "+")
		GetDlgItem(IDC_BUTTON1)->SetWindowText(_T("-"));
	if (tempstr == "-")
		GetDlgItem(IDC_BUTTON1)->SetWindowText(_T("x"));
	if (tempstr == "x")
		GetDlgItem(IDC_BUTTON1)->SetWindowText(_T("/"));
	if (tempstr == "/")
		GetDlgItem(IDC_BUTTON1)->SetWindowText(_T("����"));
	if (tempstr == "����")
		GetDlgItem(IDC_BUTTON1)->SetWindowText(_T("����"));
	if (tempstr == "����")
		GetDlgItem(IDC_BUTTON1)->SetWindowText(_T("+"));
}


void CMy4141Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString tempstr;
	double t;
	GetDlgItem(IDC_BUTTON1)->GetWindowText(tempstr);
	this->UpdateData(true);
	if (tempstr == "+")
		z = x + y;
	if (tempstr == "-")
		z = x - y;
	if (tempstr == "x")
		z = x * y;
	if (tempstr == "/")
		z = x / y;
	if (tempstr == "����")
	{
		t = double(x);
		z = sqrt(t);
	}
	if (tempstr == "����")
		z = 1 / x;
	UpdateData(false);

}
