#pragma once


// Cregist 对话框

class Cregist : public CDialog
{
	DECLARE_DYNAMIC(Cregist)

public:
	Cregist(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cregist();

// 对话框数据
	enum { IDD = IDD_REGIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString SNAME;
	CString PASSWORD;
	afx_msg void OnBnClickedOk();
};
