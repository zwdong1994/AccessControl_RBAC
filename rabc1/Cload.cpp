// Cload.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cload.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cload �Ի���

IMPLEMENT_DYNAMIC(Cload, CDialog)

Cload::Cload(CWnd* pParent /*=NULL*/)
	: CDialog(Cload::IDD, pParent)
	, ROUTE(_T(""))
{

}

Cload::~Cload()
{
}

void Cload::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ROUTE);
}


BEGIN_MESSAGE_MAP(Cload, CDialog)
	ON_BN_CLICKED(IDOK, &Cload::OnBnClickedOk)
END_MESSAGE_MAP()


// Cload ��Ϣ�������


void Cload::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	char rout[30];
	sprintf(rout,"%s",ROUTE);
	if(ROUTE.IsEmpty())
	{
		MessageBox(_T("·������Ϊ�գ�"));
		return;
	}
	if(mann.load(rout)==0)
	{
		MessageBox(_T("��ȡʧ�ܣ�"));
		return;
	}
	CDialog::OnOK();
}
