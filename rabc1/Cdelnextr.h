#pragma once


// Cdelnextr �Ի���

class Cdelnextr : public CDialog
{
	DECLARE_DYNAMIC(Cdelnextr)

public:
	Cdelnextr(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cdelnextr();

// �Ի�������
	enum { IDD = IDD_DELNEXTR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	CString RNAMECHILD;
	afx_msg void OnBnClickedOk();
};
