
// 414-2-4View.h : CMy41424View 类的接口
//

#pragma once


class CMy41424View : public CView
{
protected: // 仅从序列化创建
	CMy41424View();
	DECLARE_DYNCREATE(CMy41424View)

// 特性
public:
	CMy41424Doc* GetDocument() const;

// 操作
public:
	int x, y, z;
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
	virtual ~CMy41424View();
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

#ifndef _DEBUG  // 414-2-4View.cpp 中的调试版本
inline CMy41424Doc* CMy41424View::GetDocument() const
   { return reinterpret_cast<CMy41424Doc*>(m_pDocument); }
#endif

