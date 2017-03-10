#pragma once


// Cjuesezhipai 对话框

class Cjuesezhipai : public CDialog
{
	DECLARE_DYNAMIC(Cjuesezhipai)

public:
	Cjuesezhipai(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cjuesezhipai();

// 对话框数据
	enum { IDD = IDD_JUESEZHIPAI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	afx_msg void OnBnClickedOk();
};
