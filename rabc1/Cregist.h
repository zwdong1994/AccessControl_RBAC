#pragma once


// Cregist �Ի���

class Cregist : public CDialog
{
	DECLARE_DYNAMIC(Cregist)

public:
	Cregist(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cregist();

// �Ի�������
	enum { IDD = IDD_REGIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString SNAME;
	CString PASSWORD;
	afx_msg void OnBnClickedOk();
};
