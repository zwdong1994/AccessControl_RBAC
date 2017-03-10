// Caddnextr.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Caddnextr.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Caddnextr �Ի���

IMPLEMENT_DYNAMIC(Caddnextr, CDialog)

Caddnextr::Caddnextr(CWnd* pParent /*=NULL*/)
	: CDialog(Caddnextr::IDD, pParent)
	, RNAME(_T(""))
	, RNAMECHILD(_T(""))
{

}

Caddnextr::~Caddnextr()
{
}

void Caddnextr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
	DDX_Text(pDX, IDC_EDIT2, RNAMECHILD);
}


BEGIN_MESSAGE_MAP(Caddnextr, CDialog)
	ON_BN_CLICKED(IDOK, &Caddnextr::OnBnClickedOk)
END_MESSAGE_MAP()


// Caddnextr ��Ϣ�������


void Caddnextr::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	char rname[20],rnamechild[20];
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
	if(RNAMECHILD.IsEmpty())
	{
		MessageBox(_T("�¼���ɫ������Ϊ�գ�"));
		return;
	}
	sprintf(rname,"%s",RNAME);
	sprintf(rnamechild,"%s",RNAMECHILD);
	if(mann.add_next_r(rname,rnamechild)==0)
	{
		MessageBox(_T("�¼���ɫ���ʧ�ܣ�"));
		return;
	}
	CDialog::OnOK();
}
