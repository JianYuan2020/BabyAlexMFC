
// BabyAlexMFCView.cpp : implementation of the CBabyAlexMFCView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "BabyAlexMFC.h"
#endif

#include "BabyAlexMFCDoc.h"
#include "BabyAlexMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBabyAlexMFCView

IMPLEMENT_DYNCREATE(CBabyAlexMFCView, CView)

BEGIN_MESSAGE_MAP(CBabyAlexMFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBabyAlexMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CBabyAlexMFCView construction/destruction

CBabyAlexMFCView::CBabyAlexMFCView() noexcept
{
	// TODO: add construction code here

}

CBabyAlexMFCView::~CBabyAlexMFCView()
{
}

BOOL CBabyAlexMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CBabyAlexMFCView drawing

void CBabyAlexMFCView::OnDraw(CDC* /*pDC*/)
{
	CBabyAlexMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CBabyAlexMFCView printing


void CBabyAlexMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBabyAlexMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBabyAlexMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBabyAlexMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CBabyAlexMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBabyAlexMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBabyAlexMFCView diagnostics

#ifdef _DEBUG
void CBabyAlexMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CBabyAlexMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBabyAlexMFCDoc* CBabyAlexMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBabyAlexMFCDoc)));
	return (CBabyAlexMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CBabyAlexMFCView message handlers
