#pragma once


// Cjuesezhipai �Ի���

class Cjuesezhipai : public CDialog
{
	DECLARE_DYNAMIC(Cjuesezhipai)

public:
	Cjuesezhipai(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cjuesezhipai();

// �Ի�������
	enum { IDD = IDD_JUESEZHIPAI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	afx_msg void OnBnClickedOk();
};
