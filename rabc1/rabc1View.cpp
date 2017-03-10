
// rabc1View.cpp : Crabc1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "rabc1.h"
#endif

#include "rabc1Doc.h"
#include "rabc1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Crabc1View

IMPLEMENT_DYNCREATE(Crabc1View, CView)

BEGIN_MESSAGE_MAP(Crabc1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Crabc1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Crabc1View 构造/析构

Crabc1View::Crabc1View()
{
	// TODO: 在此处添加构造代码

}

Crabc1View::~Crabc1View()
{
}

BOOL Crabc1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Crabc1View 绘制

void Crabc1View::OnDraw(CDC* /*pDC*/)
{
	Crabc1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Crabc1View 打印


void Crabc1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Crabc1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Crabc1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Crabc1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void Crabc1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Crabc1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Crabc1View 诊断

#ifdef _DEBUG
void Crabc1View::AssertValid() const
{
	CView::AssertValid();
}

void Crabc1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Crabc1Doc* Crabc1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Crabc1Doc)));
	return (Crabc1Doc*)m_pDocument;
}
#endif //_DEBUG


// Crabc1View 消息处理程序
