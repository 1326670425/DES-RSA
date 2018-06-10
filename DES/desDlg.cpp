
// desDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "des.h"
#include "desDlg.h"
#include "afxdialogex.h"
#include "main.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CdesDlg �Ի���




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


// CdesDlg ��Ϣ�������

BOOL CdesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	kyu=0;
	syu=0;
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CdesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CdesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CdesDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	CString s,k;
	s = m_input;
	k = m_key;
	kyu = k.GetLength()%8;
	syu = s.GetLength()%8;
	
	main m ;

	//�������
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
			//key1����
			cipher = m.encrypt(plain);
			m.generateKeys(key2);
			//key2����
			plain = m.decrypt(cipher);
			m.generateKeys(key1);
			//key1�ټ���
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
			//key1����
			cipher = m.encrypt(plain);
			m.generateKeys(key2);
			//key2����
			plain = m.decrypt(cipher);
			m.generateKeys(key3);
			//key3����
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
			//key1����
			cipher = m.decrypt(plain);
			m.generateKeys(key2);
			//key2����
			plain = m.encrypt(cipher);
			m.generateKeys(key1);
			//key1�ټ���
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
			//key3����
			cipher = m.decrypt(plain);
			m.generateKeys(key2);
			//key2����
			plain = m.encrypt(cipher);
			m.generateKeys(key1);
			//key1����
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CdesDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

