#pragma once


// Clogin �Ի���

class Clogin : public CDialog
{
	DECLARE_DYNAMIC(Clogin)

public:
	Clogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Clogin();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	CString SNAME;
	CString PASSWORD;
};
