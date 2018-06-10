
// desDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "des.h"
#include "desDlg.h"
#include "afxdialogex.h"
#include "main.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CdesDlg 对话框




CdesDlg::CdesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdesDlg::IDD, pParent)
	, m_input(_T(""))
	, m_output(_T(""))
	, m_key(_T(""))
	, m_radio1(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT, m_input);
	DDX_Text(pDX, IDC_OUTPUT, m_output);
	DDX_Text(pDX, IDC_KEY, m_key);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
}

BEGIN_MESSAGE_MAP(CdesDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CdesDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CdesDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_KEY, &CdesDlg::OnEnChangeKey)
	ON_BN_CLICKED(IDC_RADIO1, &CdesDlg::OnBnClickedRadio1)

END_MESSAGE_MAP()


// CdesDlg 消息处理程序

BOOL CdesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	kyu=0;
	syu=0;
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	//GetDlgItem(IDC_RADIO1)->SetCheck(true);


	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CdesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CdesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CdesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CdesDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CString s,k;
	s = m_input;
	k = m_key;
	kyu = k.GetLength()%8;
	syu = s.GetLength()%8;
	
	main m ;

	//明文填充
	s = m.filling(s,syu,1,0);

	//string str = CT2A(s.GetBuffer());
	//bitset<64> test(str);

	//string s,k;
	//s = CT2A(m_input.GetBuffer());
	//k = CT2A(m_key.GetBuffer());
	//bitset<64> plain(s);
	//bitset<64> key(k);
	bitset<64> plain;
	bitset<64> key;
	bitset<64> key1;
	bitset<64> key2;
	bitset<64> key3;
	bitset<64> cipher;

	int n = s.GetLength()/8;
	int x = 0;
	CString tmp;
	switch(m_radio1)
	{
	case 0:
		k = m.filling(k,kyu,1,1);
		key = m.charToBitset(m.CStringtoChar(k));  
		m.generateKeys(key);
		while(x<n)
		{
			plain = m.charToBitset(m.CStringtoChar(s.Mid(8*x,8+8*x)));  
			cipher = m.encrypt(plain);
			tmp += cipher.to_string().c_str();
			x++;
		}
		break;
	case 1:
		k = m.filling(k,kyu,2,1);
		key1 = m.charToBitset(m.CStringtoChar(k.Mid(0,8)));
		key2 = m.charToBitset(m.CStringtoChar(k.Mid(8,16)));
		while(x<n)
		{
			m.generateKeys(key1);
			plain = m.charToBitset(m.CStringtoChar(s.Mid(8*x,8+8*x)));  
			//key1加密
			cipher = m.encrypt(plain);
			m.generateKeys(key2);
			//key2解密
			plain = m.decrypt(cipher);
			m.generateKeys(key1);
			//key1再加密
			cipher = m.encrypt(plain);

			tmp += cipher.to_string().c_str();
			x++;
		}
		break;
	case 2:
		k = m.filling(k,kyu,3,1);
		key1 = m.charToBitset(m.CStringtoChar(k.Mid(0,8)));
		key2 = m.charToBitset(m.CStringtoChar(k.Mid(8,16)));
		key3 = m.charToBitset(m.CStringtoChar(k.Mid(16,24)));
		while(x<n)
		{
			m.generateKeys(key1);
			plain = m.charToBitset(m.CStringtoChar(s.Mid(8*x,8+8*x)));  
			//key1加密
			cipher = m.encrypt(plain);
			m.generateKeys(key2);
			//key2解密
			plain = m.decrypt(cipher);
			m.generateKeys(key3);
			//key3加密
			cipher = m.encrypt(plain);

			tmp += cipher.to_string().c_str();
			x++;
		}
		break;
	}
	m_output = tmp;
	UpdateData(false);

}


void CdesDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	CString s,k;
	s = m_output;
	k = m_key;


	//bitset<64> key(kb);
	
	main m ;
	string sb,kb;

	bitset<64> key;
	bitset<64> key1;
	bitset<64> key2;
	bitset<64> key3;
	bitset<64> cipher;
	int n = s.GetLength()/64;
	int x = 0;
	CString tmp;
	char ch[9]={0};
	switch(m_radio1)
	{
	case 0:
		k = m.filling(k,kyu,1,1);
		key = m.charToBitset(m.CStringtoChar(k.Mid(0,8)));  
		m.generateKeys(key);
		while(x<n)
		{
			CString ss= s.Mid(64*x,64+64*x);
			sb = CT2A(ss.GetBuffer());
			bitset<64> plain(sb);
			cipher = m.decrypt(plain);
			m.BitstoByteArray(ch,cipher);
			USES_CONVERSION;
			tmp += A2T(ch);
			x++;
		}
		break;
	case 1:
		k = m.filling(k,kyu,2,1);
		key1 = m.charToBitset(m.CStringtoChar(k.Mid(0,8)));
		key2 = m.charToBitset(m.CStringtoChar(k.Mid(8,16)));
		while(x<n)
		{
			m.generateKeys(key1);
			CString ss= s.Mid(64*x,64+64*x);
			sb = CT2A(ss.GetBuffer());

			bitset<64> plain(sb); 
			//key1加密
			cipher = m.decrypt(plain);
			m.generateKeys(key2);
			//key2解密
			plain = m.encrypt(cipher);
			m.generateKeys(key1);
			//key1再加密
			cipher = m.decrypt(plain);

			m.BitstoByteArray(ch,cipher);
			USES_CONVERSION;
			tmp += A2T(ch);
			x++;
		}
		break;
	case 2:
		k = m.filling(k,kyu,3,1);
		key1 = m.charToBitset(m.CStringtoChar(k.Mid(0,8)));
		key2 = m.charToBitset(m.CStringtoChar(k.Mid(8,16)));
		key3 = m.charToBitset(m.CStringtoChar(k.Mid(16,24)));
		while(x<n)
		{
			m.generateKeys(key3);
			CString ss= s.Mid(64*x,64+64*x);
			sb = CT2A(ss.GetBuffer());

			bitset<64> plain(sb);  
			//key3解密
			cipher = m.decrypt(plain);
			m.generateKeys(key2);
			//key2加密
			plain = m.encrypt(cipher);
			m.generateKeys(key1);
			//key1解密
			cipher = m.decrypt(plain);

			m.BitstoByteArray(ch,cipher);
			USES_CONVERSION;
			tmp += A2T(ch);
			x++;
		}
		break;
	}

	//bitset<64> plain = m.charToBitset(m.CStringtoChar(s));  
	//key = m.charToBitset(m.CStringtoChar(k));  
 //   m.generateKeys(key);  
 //  
	//cipher = m.decrypt(plain);
	////string str = cipher.to_string();
	////char* ch = const_cast<char*>(str.c_str());

	//char ch[9]={0};;
	//m.BitstoByteArray(ch,cipher);

	//char* test = "romantic";

	//char* test = (char*)&cipher;
	//char test2[8]={0};
	//for(int i=0;i<8;i++)
	//{
	//	test2[i]=test[i];
	//}
	//USES_CONVERSION;
	//m_input = A2T(ch);
	if(syu!=0)
		m_input = tmp.Mid(0,tmp.GetLength()-(8-syu));
	else
		m_input = tmp;
	//m_input =  cipher.to_string().c_str();
	UpdateData(false);
}


void CdesDlg::OnEnChangeKey()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CdesDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
}

