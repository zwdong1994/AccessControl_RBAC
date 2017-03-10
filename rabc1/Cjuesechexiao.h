#pragma once


// Cjuesechexiao 对话框

class Cjuesechexiao : public CDialog
{
	DECLARE_DYNAMIC(Cjuesechexiao)

public:
	Cjuesechexiao(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cjuesechexiao();

// 对话框数据
	enum { IDD = IDD_JUESECHEXIAO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	afx_msg void OnBnClickedOk();
};
