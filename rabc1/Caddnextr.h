#pragma once


// Caddnextr �Ի���

class Caddnextr : public CDialog
{
	DECLARE_DYNAMIC(Caddnextr)

public:
	Caddnextr(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Caddnextr();

// �Ի�������
	enum { IDD = IDD_ADDNEXTR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	CString RNAMECHILD;
	afx_msg void OnBnClickedOk();
};
