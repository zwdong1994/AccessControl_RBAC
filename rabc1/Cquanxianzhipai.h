#pragma once


// Cquanxianzhipai �Ի���

class Cquanxianzhipai : public CDialog
{
	DECLARE_DYNAMIC(Cquanxianzhipai)

public:
	Cquanxianzhipai(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cquanxianzhipai();

// �Ի�������
	enum { IDD = IDD_QUANXIANZHIPAI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	CString PNAME;
	afx_msg void OnBnClickedOk();
};
