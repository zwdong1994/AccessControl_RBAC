// Cdelupon.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cdelupon.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cdelupon �Ի���

IMPLEMENT_DYNAMIC(Cdelupon, CDialog)

Cdelupon::Cdelupon(CWnd* pParent /*=NULL*/)
	: CDialog(Cdelupon::IDD, pParent)
	, RNAME(_T(""))
	, RNAMEFATHER(_T(""))
{

}

Cdelupon::~Cdelupon()
{
}

void Cdelupon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
	DDX_Text(pDX, IDC_EDIT2, RNAMEFATHER);
}


BEGIN_MESSAGE_MAP(Cdelupon, CDialog)
	ON_BN_CLICKED(IDOK, &Cdelupon::OnBnClickedOk)
END_MESSAGE_MAP()


// Cdelupon ��Ϣ�������


void Cdelupon::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	char rname[20],rnamefather[20];
	if(strcmp(mann.current_sname,"\0")==0)
	{
		MessageBox(_T("δ��¼��"));
		return;
	}
	if(RNAME.IsEmpty())
	{
		MessageBox(_T("��ɫ������Ϊ�գ�"));
		return;
	}
	if(RNAMEFATHER.IsEmpty())
	{
		MessageBox(_T("�ϼ���ɫ������Ϊ�գ�"));
		return;
	}
	sprintf(rname,"%s",RNAME);
	sprintf(rnamefather,"%s",RNAMEFATHER);
	if(mann.del_upon_r(rname,rnamefather)==0)
	{
		MessageBox(_T("�ϼ���ɫɾ��ʧ�ܣ�"));
		return;
	}
	CDialog::OnOK();
}
