#pragma once


// Cdelupon �Ի���

class Cdelupon : public CDialog
{
	DECLARE_DYNAMIC(Cdelupon)

public:
	Cdelupon(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cdelupon();

// �Ի�������
	enum { IDD = IDD_DELUPON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	CString RNAMEFATHER;
	afx_msg void OnBnClickedOk();
};
