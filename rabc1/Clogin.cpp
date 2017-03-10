// Clogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Clogin.h"
#include "afxdialogex.h"
#include "Cregist.h"

#include "stdlib.h"


mannager mann;
// Clogin �Ի���

IMPLEMENT_DYNAMIC(Clogin, CDialog)

Clogin::Clogin(CWnd* pParent /*=NULL*/)
	: CDialog(Clogin::IDD, pParent)
	, SNAME(_T(""))
	, PASSWORD(_T(""))
{

}

Clogin::~Clogin()
{
}

void Clogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, SNAME);
	DDX_Text(pDX, IDC_EDIT2, PASSWORD);
}


BEGIN_MESSAGE_MAP(Clogin, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Clogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &Clogin::OnBnClickedOk)
END_MESSAGE_MAP()


// Clogin ��Ϣ�������


void Clogin::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	Cregist reg;
	reg.DoModal();
}


void Clogin::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	UpdateData();
	char sname[20];
	char password[20];
	if(SNAME.IsEmpty())
	{
		MessageBox(_T("�û�������Ϊ�գ�"));
		return;
	}
	if(PASSWORD.IsEmpty())
	{
		MessageBox(_T("���벻��Ϊ�գ�"));
		return;
	}
	sprintf(sname,"%s",SNAME);
	sprintf(password,"%s",PASSWORD);
	if(mann.login(sname,password)==0)
	{
		MessageBox(_T("�û��������������"));
		return;
	}
	CDialog::OnOK();
}
