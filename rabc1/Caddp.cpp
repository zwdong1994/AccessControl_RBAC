// Caddp.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Caddp.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Caddp �Ի���

IMPLEMENT_DYNAMIC(Caddp, CDialog)

Caddp::Caddp(CWnd* pParent /*=NULL*/)
	: CDialog(Caddp::IDD, pParent)
	, PNAME(_T(""))
{

}

Caddp::~Caddp()
{
}

void Caddp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, PNAME);
}


BEGIN_MESSAGE_MAP(Caddp, CDialog)
	ON_BN_CLICKED(IDOK, &Caddp::OnBnClickedOk)
END_MESSAGE_MAP()


// Caddp ��Ϣ�������


void Caddp::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	char pname[20];
	if(strcmp(mann.current_sname,"\0")==0)
	{
		MessageBox(_T("δ��¼��"));
		return;
	}
	if(PNAME.IsEmpty())
	{
		MessageBox(_T("Ȩ��������Ϊ�գ�"));
		return;
	}
	sprintf(pname,"%s",PNAME);
	if(mann.add_p(pname)==0)
	{
		MessageBox(_T("���Ȩ��ʧ�ܣ�"));
		return;
	}
	CDialog::OnOK();
}
