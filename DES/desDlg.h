
// desDlg.h : ͷ�ļ�
//

#pragma once
#include <iostream> 
#include <fstream> 
#include <bitset>  
#include <string> 

// CdesDlg �Ի���
class CdesDlg : public CDialogEx
{
// ����
public:

	int kyu;
	int syu;

	CdesDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
