
// rabc1View.h : Crabc1View ��Ľӿ�
//

#pragma once


class Crabc1View : public CView
{
protected: // �������л�����
	Crabc1View();
	DECLARE_DYNCREATE(Crabc1View)

// ����
public:
	Crabc1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Crabc1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // rabc1View.cpp �еĵ��԰汾
inline Crabc1Doc* Crabc1View::GetDocument() const
   { return reinterpret_cast<Crabc1Doc*>(m_pDocument); }
#endif

