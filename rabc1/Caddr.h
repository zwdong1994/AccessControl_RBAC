#pragma once


// Caddr 对话框

class Caddr : public CDialog
{
	DECLARE_DYNAMIC(Caddr)

public:
	Caddr(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Caddr();

// 对话框数据
	enum { IDD = IDD_ADDR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString RNAME;
};
