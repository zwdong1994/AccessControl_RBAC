#pragma once


// Cquanxianzhipai 对话框

class Cquanxianzhipai : public CDialog
{
	DECLARE_DYNAMIC(Cquanxianzhipai)

public:
	Cquanxianzhipai(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cquanxianzhipai();

// 对话框数据
	enum { IDD = IDD_QUANXIANZHIPAI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	CString PNAME;
	afx_msg void OnBnClickedOk();
};
