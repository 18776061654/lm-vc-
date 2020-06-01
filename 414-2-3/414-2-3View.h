
// 414-2-3View.h : CMy41423View 类的接口
//

#pragma once


class CMy41423View : public CView
{
protected: // 仅从序列化创建
	CMy41423View();
	DECLARE_DYNCREATE(CMy41423View)

// 特性
public:
	CMy41423Doc* GetDocument() const;

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
	virtual ~CMy41423View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 414-2-3View.cpp 中的调试版本
inline CMy41423Doc* CMy41423View::GetDocument() const
   { return reinterpret_cast<CMy41423Doc*>(m_pDocument); }
#endif

