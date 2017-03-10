// Cjuesechexiao.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cjuesechexiao.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cjuesechexiao �Ի���

IMPLEMENT_DYNAMIC(Cjuesechexiao, CDialog)

Cjuesechexiao::Cjuesechexiao(CWnd* pParent /*=NULL*/)
	: CDialog(Cjuesechexiao::IDD, pParent)
	, RNAME(_T(""))
{

}

Cjuesechexiao::~Cjuesechexiao()
{
}

void Cjuesechexiao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
}


BEGIN_MESSAGE_MAP(Cjuesechexiao, CDialog)
	ON_BN_CLICKED(IDOK, &Cjuesechexiao::OnBnClickedOk)
END_MESSAGE_MAP()


// Cjuesechexiao ��Ϣ�������


void Cjuesechexiao::OnBnClickedOk()
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
	if(mann.chexiao_ua(mann.current_sname,rname)==0)
	{
		MessageBox(_T("����ʧ�ܣ�"));
		return;
	}
	CDialog::OnOK();
}
