#pragma once


// Cjuesechexiao �Ի���

class Cjuesechexiao : public CDialog
{
	DECLARE_DYNAMIC(Cjuesechexiao)

public:
	Cjuesechexiao(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cjuesechexiao();

// �Ի�������
	enum { IDD = IDD_JUESECHEXIAO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	afx_msg void OnBnClickedOk();
};
