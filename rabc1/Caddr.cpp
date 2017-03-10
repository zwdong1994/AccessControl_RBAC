// Caddr.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Caddr.h"
#include "afxdialogex.h"
#include "tianjia.h"


// Caddr �Ի���

IMPLEMENT_DYNAMIC(Caddr, CDialog)

Caddr::Caddr(CWnd* pParent /*=NULL*/)
	: CDialog(Caddr::IDD, pParent)
	, RNAME(_T(""))
{

}

Caddr::~Caddr()
{
}

void Caddr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
}


BEGIN_MESSAGE_MAP(Caddr, CDialog)
	ON_BN_CLICKED(IDOK, &Caddr::OnBnClickedOk)
END_MESSAGE_MAP()


// Caddr ��Ϣ�������


void Caddr::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	char rname[20];
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
	sprintf(rname,"%s",RNAME);
	if(mann.add_r(rname)==0)
	{
		MessageBox(_T("��ӽ�ɫʧ�ܣ�"));
		return;
	}
	CDialog::OnOK();
}
