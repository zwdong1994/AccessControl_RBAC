#pragma once


// Caddp �Ի���

class Caddp : public CDialog
{
	DECLARE_DYNAMIC(Caddp)

public:
	Caddp(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Caddp();

// �Ի�������
	enum { IDD = IDD_ADDP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString PNAME;
};
