// Csave.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Csave.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Csave 对话框

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


// Csave 消息处理程序


void Csave::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	char rout[30];
	sprintf(rout,"%s",ROUTE);
	if(ROUTE.IsEmpty())
	{
		MessageBox(_T("路径不能为空！"));
		return;
	}
	if(mann.save(rout)==0)
	{
		MessageBox(_T("保存失败！"));
		return;
	}
	CDialog::OnOK();
}
