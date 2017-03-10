// Cquanxianzhipai.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cquanxianzhipai.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cquanxianzhipai �Ի���

IMPLEMENT_DYNAMIC(Cquanxianzhipai, CDialog)

Cquanxianzhipai::Cquanxianzhipai(CWnd* pParent /*=NULL*/)
	: CDialog(Cquanxianzhipai::IDD, pParent)
	, RNAME(_T(""))
	, PNAME(_T(""))
{

}

Cquanxianzhipai::~Cquanxianzhipai()
{
}

void Cquanxianzhipai::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
	DDX_Text(pDX, IDC_EDIT2, PNAME);
}


BEGIN_MESSAGE_MAP(Cquanxianzhipai, CDialog)
	ON_BN_CLICKED(IDOK, &Cquanxianzhipai::OnBnClickedOk)
END_MESSAGE_MAP()


// Cquanxianzhipai ��Ϣ�������


void Cquanxianzhipai::OnBnClickedOk()
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
	if(mann.pa_zhipai(rname,pname)==0)
	{
		MessageBox(_T("ָ��ʧ�ܣ�"));
		return;
	}
	CDialog::OnOK();
}
