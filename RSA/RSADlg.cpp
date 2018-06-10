
// RSADlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RSA.h"
#include "RSADlg.h"
#include "afxdialogex.h"
#include "math.h"
#include "MD5.h"

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


// CRSADlg �Ի���




CRSADlg::CRSADlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRSADlg::IDD, pParent)
	, m_p(0)
	, m_q(0)
	, m_n(0)
	, m_N(0)
	, m_e(0)
	, m_d(0)
	, m_input(_T(""))
	, m_output(_T(""))
	, m_md5(_T(""))
	, m_msg(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRSADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_P, m_p);
	DDX_Text(pDX, IDC_Q, m_q);
	DDX_Text(pDX, IDC_N1, m_n);
	DDX_Text(pDX, IDC_N, m_N);
	DDX_Text(pDX, IDC_E, m_e);
	DDX_Text(pDX, IDC_D, m_d);
	DDX_Text(pDX, IDC_EDIT2, m_input);
	DDX_Text(pDX, IDC_EDIT1, m_output);
	DDX_Text(pDX, IDC_MD5, m_md5);
	DDX_Text(pDX, IDC_EDIT3, m_msg);
}

BEGIN_MESSAGE_MAP(CRSADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_CREATE, &CRSADlg::OnBnClickedCreate)
	ON_BN_CLICKED(IDC_EN, &CRSADlg::OnBnClickedEn)
	ON_BN_CLICKED(IDC_DE, &CRSADlg::OnBnClickedDe)
	ON_BN_CLICKED(IDC_CREATEMD5, &CRSADlg::OnBnClickedCreatemd5)
	ON_BN_CLICKED(IDC_MSG, &CRSADlg::OnBnClickedMsg)
END_MESSAGE_MAP()


// CRSADlg ��Ϣ�������

BOOL CRSADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

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

void CRSADlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRSADlg::OnPaint()
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
HCURSOR CRSADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CRSADlg::OnBnClickedCreate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	srand(time(0));
	while(true)
	{
		//m_p = rand()%50;
		m_p = 3;
		if(isPrime(m_p))
			break;
	}
	while(true)
	{
		//m_q = rand()%50;
		m_q = 11;
		if(isPrime(m_q) && m_q!=m_p)
			break;
	}
	m_n = m_p * m_q;
	m_N =(m_p-1)*(m_q-1);

	long i = 3;
	//i = rand()%3+10;
	for(;i<m_N;i++)
	{
		if(isPrime(i) && gcd(m_N,i) ==1)
		{
			m_e = i;
			break;
		}
	}
	m_d = Euler(m_e,m_N);
	UpdateData(false);
}


bool CRSADlg::isPrime(long n)
{
	long i=2;
	for(;i<=(long)sqrt((double)n);i++)
	{
		if(n%i==0)
			break;
	}
	if(i>(long)sqrt((double)n))
		return true;
	return false;
}


long CRSADlg::gcd(long a, long b)
{
	if(a==0)
		return b;
	else
		return gcd(b%a,a);
}


long CRSADlg::Euler(long e, long N)
{
	long d[10] = {0};
	int i=0;
	for(int x=1;x<N;x++)
	{
		if((e*x)%N == 1)
		{
			d[i] = x;
			i++;
		}

	}
	long dd = 0;
	dd = d[0];
	//while(true)
	//{
	//	if(dd<=10)
	//		break;
	//	dd = d[rand()%i];
	//}

	//delete d;
	return dd;
}


void CRSADlg::OnBnClickedEn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	CString temp,str;
	int n ;
	int len = m_md5.GetLength();
	for(int i=0;i<len;i++)
	{
		n = hexToDec(m_md5.Mid(i,1));
		temp.Format(_T("%ld%s"),power(n,(int)m_d,m_n),_T("."));
		str += temp;
		
	}
	m_output = m_input+" "+str;
	UpdateData(false);
}


long CRSADlg::power(int m, int e, long n)
{
	long long p = (long long)pow((double)m,(double)e);
	return p%n;
}


void CRSADlg::OnBnClickedDe()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	CStringArray strArray;
	CString temp = m_output;
	CString str;
	int pos = -1;
	CString msg;
	pos = temp.Find(' ');
	msg = temp.Left(pos);
	temp.Delete(0,pos+1);

	string s;
	s = CT2A(msg.GetBuffer());
	CMD5 md5;
	char *p = (char*)s.data();
	md5.GenerateMD5((unsigned char*)p,s.length());
	//m_md5 = md5.ToString().c_str();

	while((pos=temp.Find('.'))!=-1)
	{
		strArray.Add(temp.Left(pos));
		temp.Delete(0,pos+1);
	}
	//CString s = strArray[0];
	temp ="";
	
	for(int i=0;i<strArray.GetSize();i++)
	{
		int t = atoi(CStringtoChar(strArray[i]));
		long p = power(t,(int)m_e,m_n);
		temp.Format(_T("%s%c"),temp,p+60);
		if(p<10)
			temp.Format(_T("%d"),p);
		else
			temp.Format(_T("%c"),p+87);
		str += temp;
	}
	if(md5.ToString().c_str()==str)
		GetDlgItem(ID_TEXT)->SetWindowText(_T("��֤�ɹ�"));
	else
		GetDlgItem(ID_TEXT)->SetWindowText(_T("��֤ʧ��"));
	UpdateData(false);
}


char* CRSADlg::CStringtoChar(CString s)
{
	wchar_t *wChar = s.GetBuffer(s.GetLength());
	s.ReleaseBuffer();
	// ���õ���wchar* ����תΪ char*����
	size_t len = wcslen(wChar) + 1;
	size_t converted = 0;
	char *cChar;
	cChar = (char*)malloc(len*sizeof(char));
	wcstombs_s(&converted, cChar, len, wChar, _TRUNCATE);
	return cChar;
}


void CRSADlg::OnBnClickedCreatemd5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	string str;
	str = CT2A(m_input.GetBuffer());
	CMD5 md5;
	char *p = (char*)str.data();
	md5.GenerateMD5((unsigned char*)p,str.length());
	m_md5 = md5.ToString().c_str();
	
	UpdateData(false);
}


int CRSADlg::hexToDec(CString cs)
{
	string s;
	s = CT2A(cs.GetBuffer());
	int count = s.length();
	int sum=0;  

	for(int i=0;i<count;i++)
	{  
		if(s[i]>='0'&&s[i]<='9')//�����ַ���ת��  
		{  
			sum =(s[i]-48);
		}  
		else if(s[i]>='a'&&s[i]<='f')//��ĸ�ַ���ת��  
		{  
			sum =(s[i]-87);  
		}  
	}  
	return sum;
}


void CRSADlg::OnBnClickedMsg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	CString temp = m_output;
	int pos = -1;
	CString msg;
	pos = temp.Find(' ');
	msg = temp.Left(pos);
	temp.Delete(0,pos+1);
	m_msg = msg;
	UpdateData(false);
}
