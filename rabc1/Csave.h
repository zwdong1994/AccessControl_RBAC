#pragma once


// Csave 对话框

class Csave : public CDialog
{
	DECLARE_DYNAMIC(Csave)

public:
	Csave(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Csave();

// 对话框数据
	enum { IDD = IDD_SAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString ROUTE;
};
