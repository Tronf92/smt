
// smtView.cpp : implementation of the CsmtView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "smt.h"
#endif

#include "smtDoc.h"
#include "smtView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsmtView

IMPLEMENT_DYNCREATE(CsmtView, CView)

BEGIN_MESSAGE_MAP(CsmtView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CsmtView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CsmtView construction/destruction

CsmtView::CsmtView()
{
	// TODO: add construction code here

}

CsmtView::~CsmtView()
{
}

BOOL CsmtView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CsmtView drawing

void CsmtView::OnDraw(CDC* /*pDC*/)
{
	CsmtDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CsmtView printing


void CsmtView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CsmtView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CsmtView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CsmtView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CsmtView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CsmtView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CsmtView diagnostics

#ifdef _DEBUG
void CsmtView::AssertValid() const
{
	CView::AssertValid();
}

void CsmtView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsmtDoc* CsmtView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsmtDoc)));
	return (CsmtDoc*)m_pDocument;
}
#endif //_DEBUG


// CsmtView message handlers
