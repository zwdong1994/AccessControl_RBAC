// Csave.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "rabc1.h"
#include "Csave.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Csave �Ի���

IMPLEMENT_DYNAMIC(Csave, CDialog)

Csave::Csave(CWnd* pParent /*=NULL*/)
	: CDialog(Csave::IDD, pParent)
	, ROUTE(_T(""))
{

}

Csave::~Csave()
{
}

void Csave::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ROUTE);
}


BEGIN_MESSAGE_MAP(Csave, CDialog)
	ON_BN_CLICKED(IDOK, &Csave::OnBnClickedOk)
END_MESSAGE_MAP()


// Csave ��Ϣ�������


void Csave::OnBnClickedOk()
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
	if(mann.save(rout)==0)
	{
		MessageBox(_T("����ʧ�ܣ�"));
		return;
	}
	CDialog::OnOK();
}
