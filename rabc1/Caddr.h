#pragma once


// Caddr �Ի���

class Caddr : public CDialog
{
	DECLARE_DYNAMIC(Caddr)

public:
	Caddr(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Caddr();

// �Ի�������
	enum { IDD = IDD_ADDR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString RNAME;
};
