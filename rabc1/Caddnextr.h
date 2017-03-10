#pragma once


// Caddnextr 对话框

class Caddnextr : public CDialog
{
	DECLARE_DYNAMIC(Caddnextr)

public:
	Caddnextr(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Caddnextr();

// 对话框数据
	enum { IDD = IDD_ADDNEXTR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	CString RNAMECHILD;
	afx_msg void OnBnClickedOk();
};
