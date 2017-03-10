
// rabc1View.cpp : Crabc1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Crabc1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Crabc1View ����/����

Crabc1View::Crabc1View()
{
	// TODO: �ڴ˴���ӹ������

}

Crabc1View::~Crabc1View()
{
}

BOOL Crabc1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Crabc1View ����

void Crabc1View::OnDraw(CDC* /*pDC*/)
{
	Crabc1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Crabc1View ��ӡ


void Crabc1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Crabc1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Crabc1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Crabc1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// Crabc1View ���

#ifdef _DEBUG
void Crabc1View::AssertValid() const
{
	CView::AssertValid();
}

void Crabc1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Crabc1Doc* Crabc1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Crabc1Doc)));
	return (Crabc1Doc*)m_pDocument;
}
#endif //_DEBUG


// Crabc1View ��Ϣ�������
