
// RSADlg.h : 头文件
//

#pragma once


// CRSADlg 对话框
class CRSADlg : public CDialogEx
{
// 构造
public:
	CRSADlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_RSA_DIALOG };

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
	afx_msg void OnEnChangeN();
	long m_p;
	long m_q;
	long m_n;
	long m_N;
	long m_e;
	long m_d;
	afx_msg void OnBnClickedCreate();
	bool isPrime(long n);
	long gcd(long a, long b);
	long Euler(long e, long N);
	CString m_input;
	CString m_output;
	afx_msg void OnBnClickedEn();
	long power(int m, int e, long n);
	afx_msg void OnBnClickedDe();
	char* CStringtoChar(CString s);
	CString m_md5;
	afx_msg void OnBnClickedCreatemd5();
	int hexToDec(CString cs);
	afx_msg void OnBnClickedMsg();
	CString m_msg;
};
