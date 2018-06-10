
// desDlg.h : 头文件
//

#pragma once
#include <iostream> 
#include <fstream> 
#include <bitset>  
#include <string> 

// CdesDlg 对话框
class CdesDlg : public CDialogEx
{
// 构造
public:

	int kyu;
	int syu;

	CdesDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	CString m_input;
	CString m_output;
	CString m_key;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeKey();
	afx_msg void OnBnClickedRadio1();
	int m_radio1;

};
