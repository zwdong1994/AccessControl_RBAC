// Cdelnextr.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cdelnextr.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cdelnextr �Ի���

IMPLEMENT_DYNAMIC(Cdelnextr, CDialog)

Cdelnextr::Cdelnextr(CWnd* pParent /*=NULL*/)
	: CDialog(Cdelnextr::IDD, pParent)
	, RNAME(_T(""))
	, RNAMECHILD(_T(""))
{

}

Cdelnextr::~Cdelnextr()
{
}

void Cdelnextr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
	DDX_Text(pDX, IDC_EDIT2, RNAMECHILD);
}


BEGIN_MESSAGE_MAP(Cdelnextr, CDialog)
	ON_BN_CLICKED(IDOK, &Cdelnextr::OnBnClickedOk)
END_MESSAGE_MAP()


// Cdelnextr ��Ϣ�������


void Cdelnextr::OnBnClickedOk()
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
	if(mann.del_next_r(rname,rnamechild)==0)
	{
		MessageBox(_T("�¼���ɫɾ��ʧ�ܣ�"));
		return;
	}
	CDialog::OnOK();
}
