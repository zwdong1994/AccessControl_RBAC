#pragma once


// Cdelupon 对话框

class Cdelupon : public CDialog
{
	DECLARE_DYNAMIC(Cdelupon)

public:
	Cdelupon(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cdelupon();

// 对话框数据
	enum { IDD = IDD_DELUPON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	CString RNAMEFATHER;
	afx_msg void OnBnClickedOk();
};
