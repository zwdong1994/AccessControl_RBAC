#pragma once


// Cquanxianchexiao �Ի���

class Cquanxianchexiao : public CDialog
{
	DECLARE_DYNAMIC(Cquanxianchexiao)

public:
	Cquanxianchexiao(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cquanxianchexiao();

// �Ի�������
	enum { IDD = IDD_QUANXIANCHEXIAO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString RNAME;
	CString PNAME;
	afx_msg void OnBnClickedOk();
};
