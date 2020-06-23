
// 4.20-1View.h : CMy4201View 类的接口
//

#pragma once


class CMy4201View : public CView
{
protected: // 仅从序列化创建
	CMy4201View();
	DECLARE_DYNCREATE(CMy4201View)

// 特性
public:
	CMy4201Doc* GetDocument() const;

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
	virtual ~CMy4201View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // 4.20-1View.cpp 中的调试版本
inline CMy4201Doc* CMy4201View::GetDocument() const
   { return reinterpret_cast<CMy4201Doc*>(m_pDocument); }
#endif

