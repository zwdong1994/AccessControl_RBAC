#pragma once


// Caddp 对话框

class Caddp : public CDialog
{
	DECLARE_DYNAMIC(Caddp)

public:
	Caddp(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Caddp();

// 对话框数据
	enum { IDD = IDD_ADDP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString PNAME;
};
