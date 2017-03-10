#pragma once


// Cdelnextr 对话框

class Cdelnextr : public CDialog
{
	DECLARE_DYNAMIC(Cdelnextr)

public:
	Cdelnextr(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cdelnextr();

// 对话框数据
	enum { IDD = IDD_DELNEXTR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	CString RNAMECHILD;
	afx_msg void OnBnClickedOk();
};
