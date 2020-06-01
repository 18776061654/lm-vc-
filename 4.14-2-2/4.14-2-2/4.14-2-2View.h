
// 4.14-2-2View.h : CMy41422View 类的接口
//

#pragma once


class CMy41422View : public CView
{
protected: // 仅从序列化创建
	CMy41422View();
	DECLARE_DYNCREATE(CMy41422View)

// 特性
public:
	CMy41422Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy41422View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void On32771();
};

#ifndef _DEBUG  // 4.14-2-2View.cpp 中的调试版本
inline CMy41422Doc* CMy41422View::GetDocument() const
   { return reinterpret_cast<CMy41422Doc*>(m_pDocument); }
#endif

