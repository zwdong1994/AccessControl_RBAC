#pragma once


// Cload �Ի���

class Cload : public CDialog
{
	DECLARE_DYNAMIC(Cload)

public:
	Cload(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cload();

// �Ի�������
	enum { IDD = IDD_LOAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString ROUTE;
	afx_msg void OnBnClickedOk();
};
