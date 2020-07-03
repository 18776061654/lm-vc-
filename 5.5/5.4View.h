
// 5.4View.h : CMy54View 类的接口
//

#pragma once

class CMy54Set;

class CMy54View : public CRecordView
{
protected: // 仅从序列化创建
	CMy54View();
	DECLARE_DYNCREATE(CMy54View)

public:
	enum{ IDD = IDD_MY54_FORM };
	CMy54Set* m_pSet;

// 特性
public:
	CMy54Doc* GetDocument() const;

// 操作
public:
	
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void draw_pic(CString s);
// 实现
public:
	virtual ~CMy54View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString NAME;
	CString XUEHAO;
	CString PHONE;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // 5.4View.cpp 中的调试版本
inline CMy54Doc* CMy54View::GetDocument() const
   { return reinterpret_cast<CMy54Doc*>(m_pDocument); }
#endif

