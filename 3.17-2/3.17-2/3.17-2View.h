
// 3.17-2View.h : CMy3172View 类的接口
//

#pragma once


class CMy3172View : public CView
{
protected: // 仅从序列化创建
	CMy3172View();
	DECLARE_DYNCREATE(CMy3172View)

// 特性
public:
	CMy3172Doc* GetDocument() const;

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
	virtual ~CMy3172View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3.17-2View.cpp 中的调试版本
inline CMy3172Doc* CMy3172View::GetDocument() const
   { return reinterpret_cast<CMy3172Doc*>(m_pDocument); }
#endif

