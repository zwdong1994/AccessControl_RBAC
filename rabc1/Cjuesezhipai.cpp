// Cjuesezhipai.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cjuesezhipai.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cjuesezhipai �Ի���

IMPLEMENT_DYNAMIC(Cjuesezhipai, CDialog)

Cjuesezhipai::Cjuesezhipai(CWnd* pParent /*=NULL*/)
	: CDialog(Cjuesezhipai::IDD, pParent)
	, RNAME(_T(""))
{

}

Cjuesezhipai::~Cjuesezhipai()
{
}

void Cjuesezhipai::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
}


BEGIN_MESSAGE_MAP(Cjuesezhipai, CDialog)
	ON_BN_CLICKED(IDOK, &Cjuesezhipai::OnBnClickedOk)
END_MESSAGE_MAP()


// Cjuesezhipai ��Ϣ�������


void Cjuesezhipai::OnBnClickedOk()
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
	if(mann.zhipai_ua(mann.current_sname,rname)==0)
	{
		MessageBox(_T("ָ��ʧ�ܣ�"));
		return;
	}
	CDialog::OnOK();
}
