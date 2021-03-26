
// BabyAlexMFCView.h : interface of the CBabyAlexMFCView class
//

#pragma once


class CBabyAlexMFCView : public CView
{
protected: // create from serialization only
	CBabyAlexMFCView() noexcept;
	DECLARE_DYNCREATE(CBabyAlexMFCView)

// Attributes
public:
	CBabyAlexMFCDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CBabyAlexMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BabyAlexMFCView.cpp
inline CBabyAlexMFCDoc* CBabyAlexMFCView::GetDocument() const
   { return reinterpret_cast<CBabyAlexMFCDoc*>(m_pDocument); }
#endif

