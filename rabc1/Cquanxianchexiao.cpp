// Cquanxianchexiao.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cquanxianchexiao.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cquanxianchexiao �Ի���

IMPLEMENT_DYNAMIC(Cquanxianchexiao, CDialog)

Cquanxianchexiao::Cquanxianchexiao(CWnd* pParent /*=NULL*/)
	: CDialog(Cquanxianchexiao::IDD, pParent)
	, RNAME(_T(""))
	, PNAME(_T(""))
{

}

Cquanxianchexiao::~Cquanxianchexiao()
{
}

void Cquanxianchexiao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
	DDX_Text(pDX, IDC_EDIT2, PNAME);
}


BEGIN_MESSAGE_MAP(Cquanxianchexiao, CDialog)
	ON_BN_CLICKED(IDOK, &Cquanxianchexiao::OnBnClickedOk)
END_MESSAGE_MAP()


// Cquanxianchexiao ��Ϣ�������


void Cquanxianchexiao::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	char rname[20],pname[20];
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
	if(PNAME.IsEmpty())
	{
		MessageBox(_T("Ȩ��������Ϊ�գ�"));
		return;
	}
	sprintf(rname,"%s",RNAME);
	sprintf(pname,"%s",PNAME);
	if(mann.pa_chexiao(rname,pname)==0)
	{
		MessageBox(_T("����ʧ�ܣ�"));
		return;
	}
	CDialog::OnOK();
}
