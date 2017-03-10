#pragma once


// Cquanxianchexiao 对话框

class Cquanxianchexiao : public CDialog
{
	DECLARE_DYNAMIC(Cquanxianchexiao)

public:
	Cquanxianchexiao(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cquanxianchexiao();

// 对话框数据
	enum { IDD = IDD_QUANXIANCHEXIAO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	CString PNAME;
	afx_msg void OnBnClickedOk();
};
