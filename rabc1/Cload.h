#pragma once


// Cload 对话框

class Cload : public CDialog
{
	DECLARE_DYNAMIC(Cload)

public:
	Cload(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cload();

// 对话框数据
	enum { IDD = IDD_LOAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString ROUTE;
	afx_msg void OnBnClickedOk();
};
