#pragma once


// Csave �Ի���

class Csave : public CDialog
{
	DECLARE_DYNAMIC(Csave)

public:
	Csave(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Csave();

// �Ի�������
	enum { IDD = IDD_SAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString ROUTE;
};
