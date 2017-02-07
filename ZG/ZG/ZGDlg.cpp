
// ZGDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZG.h"
#include "ZGDlg.h"
#include "afxdialogex.h"

#include "ZRadioButton.h"
#include "ZButton.h"
#include "ZLable.h"
#include "ZFont0.h"
#include "ZWindows.h"
#include "ZGraphical.h"
#include "ZPanel.h"

extern CZGDlg *mZGDlg;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CZGDlg �Ի���



CZGDlg::CZGDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//memset(screenBuffer, 0x00ffffff, 240 * 320k);
}

void CZGDlg::setPixel(int x, int y, unsigned int color)
{
	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT) {
		return;
	}
	screenBuffer[x][y] = color;


}

unsigned int CZGDlg::getPixel(int x, int y)
{
	if (x < 0 || y < 0 || x>= SCREEN_WIDTH || y>= SCREEN_HEIGHT) {
		return 0x000000;
	}
	return screenBuffer[x][y];
}

void CZGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CZGDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CZGDlg ��Ϣ�������
#include <conio.h>
BOOL CZGDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	AllocConsole();

	mZGDlg = this;
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//
	//mZGraphical->setPixel(50, 50, 0x00ffffff);
	//mZGraphical->drawLine(70, 70, 70,70, 0x00ffffff);
	////mZGraphical->drawRect(60, 60, 5, 5, 0x00ffffff);
	//mZGraphical->drawCircle(50, 50, 11, 0x00ffffff);
	//mZGraphical->drawEdgeRect(60, 60, 0, 0, 0x00ffffff);
	//ZPanel *mZPanel1;
	//mZPanel1 = new ZPanel(0, 0, 240, 320);
	//mZPanel1->setDispaly(TRUE);
	//mZPanel = new ZPanel(60, 20, 20, 40);
	//mZPanel->setBackgroundColor(0xff0000);
	//mZPanel->setDispaly(TRUE);
	mZFont0 = new ZFont0();
	zMsgDispose = new ZMsgDispose();
	ZWindows *desktop = new ZWindows(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (u16*)L"d");
	desktop->setCustom(TRUE);
	desktop->setFont(mZFont0);


	mZWindow = new ZWindows(0, 0, 300, 200, (u16*)L"w");
	mZWindow->setWindowEventCallBack(this);
	//mZWindow->setFont(mZFont0);
	//zMsgDispose->addControlPanel(mZWindow);
	
	mZLable = new ZLable(0, 60, 100, 20, (u16*)L"���");
	mZLable->setControlEventCallBack(this);

	mZButton = new ZButton(16, 16, 100, 30, (u16*)L"���");
	mZButton->setControlEventCallBack(this);

	ZWindows *tZWindows=new ZWindows(80, 80, 200, 80, (u16*)L"hello");
	mZWindow->setWindowEventCallBack(this);
	tZWindows->setFont(mZFont0);
	
	ZRadioButton *mZRadioButton = new ZRadioButton(150, 10, 80, 30,(Font16*)L"radio");
	
	desktop->add(mZWindow);
	desktop->add(tZWindows);

	//mZWindow->add(mZLable);
	//mZWindow->add(mZButton);
	//mZWindow->add(mZRadioButton);

	zMsgDispose->addControlPanel(desktop);
	desktop->show();
	mZWindow->setLocation(50, 50);
	//ZGraphical *mZGraphical = new ZGraphical();
	//mZGraphical->setFont(new ZFont0());
	//mZGraphical->drawStringEx(0, 0,50,50, (u16*)L"��ã�\n���硣��", 0xffffff);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CZGDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CZGDlg::OnPaint()
{
	//CPaintDC dc(this); // ���ڻ��Ƶ��豸������

	//CDC *pDC = &dc;
	//if (IsIconic())
	//{
	//	CPaintDC dc(this); // ���ڻ��Ƶ��豸������

	//	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

	//	// ʹͼ���ڹ����������о���
	//	int cxIcon = GetSystemMetrics(SM_CXICON);
	//	int cyIcon = GetSystemMetrics(SM_CYICON);
	//	CRect rect;
	//	GetClientRect(&rect);
	//	int x = (rect.Width() - cxIcon + 1) / 2;
	//	int y = (rect.Height() - cyIcon + 1) / 2;

	//	// ����ͼ��
	//	dc.DrawIcon(x, y, m_hIcon);
	//}
	//else
	//{
	//	CDialogEx::OnPaint();
		//CDC MemDC; //���ȶ���һ����ʾ�豸���� 
		//CBitmap MemBitmap;//����һ��λͼ���� 
		//				  //���������Ļ��ʾ���ݵ��ڴ���ʾ�豸 
		//MemDC.CreateCompatibleDC(NULL); //��ʱ�����ܻ�ͼ����Ϊû�еط��� ^_^ 
		//								//���潨��һ������Ļ��ʾ���ݵ�λͼ������λͼ�Ĵ�С������ô��ڵĴ�С 
		//MemBitmap.CreateCompatibleBitmap(pDC, 240, 320); //��λͼѡ�뵽�ڴ���ʾ�豸�� 
		//														//ֻ��ѡ����λͼ���ڴ���ʾ�豸���еط���ͼ������ָ����λͼ�� 
		//CBitmap *pOldBit = MemDC.SelectObject(&MemBitmap);
		////���ñ���ɫ��λͼ����ɾ����������õ��ǰ�ɫ��Ϊ���� 
		////��Ҳ�������Լ�Ӧ���õ���ɫ 
		//MemDC.FillSolidRect(0, 0, 240, 320, RGB(255, 255, 255));
		////��ͼ 
		//for (int i = 0; i < 240; i++) {
		//	for (int j = 0; j < 320; j++) {
		//		MemDC.SetPixel(i, j, screenBuffer[i][j]);
		//	}
		//}
		////���ڴ��е�ͼ��������Ļ�Ͻ�����ʾ 
		//pDC->BitBlt(0, 0, 240, 320, &MemDC, 0, 0, SRCCOPY);
		////��ͼ��ɺ������ 
		//MemBitmap.DeleteObject();
		//MemDC.DeleteDC();

		//CPaintDC dc(this); // ���ڻ��Ƶ��豸������
		//dc.Draw3dRect(5, 5, 200,200,0x00000000, 0x00ff00ff);
	
	//}
	CPaintDC dc(this); // device context for painting  
	CRect rect;//���������ͼ�����С�ľ��� 
	CDC *pDC;
	CDC MemDC;   //�������ݵ��ڴ�DC  
	CBitmap MemBitmap;  //��������֮����ָ���ȡ��ǰ�ؼ���DC   
	pDC = GetDC();
	GetClientRect(&rect);   //��ȡ�ͻ��������С  
	pDC = GetDC();
	//ѡ����ͻ��������С��ͬ��λ�ô�������λͼ  
	MemDC.CreateCompatibleDC(pDC);
	MemBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	MemDC.SelectObject(&MemBitmap);   //��λͼѡ���ڴ���  
	//MemDC.SelectObject(&pen);
	MemDC.FillSolidRect(rect, RGB(255, 255, 255));

	//�����ɫ
	for (int i = 0; i < SCREEN_WIDTH; i++) {
		for (int j = 0; j < SCREEN_HEIGHT; j++) {
			MemDC.SetPixel(i, j, screenBuffer[i][j]);
		}
	}
	//Ȼ��ʼ���ڴ����Ѿ����ƺõ�һ����ȫ�����ֵ���Ļ��  
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &MemDC, 0, 0, SRCCOPY);


	//�ڴ渴λ
	MemDC.SelectObject(MemBitmap);
}




//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CZGDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CZGDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	Msg *mMsg;
	mMsg = new Msg();
	mMsg->hwnd = NULL;
	mMsg->wParam = point.x;
	mMsg->lParam = point.y;
	mMsg->message = MOUSE_MSG_DOWN;
	mMsg->time = 0;
	mMsg->pt.x = point.x;
	mMsg->pt.y = point.y;
	zMsgDispose->addMsg(mMsg);
	zMsgDispose->msgWindowsDispose();
	flag = 1;
	CDialogEx::OnLButtonDown(nFlags, point);
	this->Invalidate();
}

void CZGDlg::windowsEventDispose(Msg * msg)
{
	//ZWindows *mZWindow;
	CString a("Message");
	switch (msg->message) {
	case MOUSE_MSG_DOWN:
		//mZWindow->setLocation(msg->wParam, msg->lParam);
		//mZLable->setText((u16*)L"��һ��..");
		//mZWindow = new ZWindows(msg->wParam, msg->lParam, 200, 200, (u16*)L"����������������������������");
		//mZWindow->setFont(mZFont0);
		//mZWindow->setWindowEventCallBack(this);
		//mZWindow->show();
	
		// TODO: Add your message handler code here and/or call default
		//MessageBox(L"down", a, 0);
		break;
	case MOUSE_MSG_RELEASE:
		// TODO: Add your message handler code here and/or call default
		//MessageBox(L"up", a, 0);
		break;
	}
	
}

void CZGDlg::ControlEventHandle(ZPanel * mZPanel, Msg * msg)
{
	if (msg->message == CONTROL_DOWN) {
		MessageBox(L"button_down", L"msg", 0);
		mZLable->setText((u16*)L"��һ��..");
	}
	else {
		//MessageBox(L"up", L"msg", 0);
	}
}


void CZGDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Msg *mMsg;
	mMsg = new Msg();
	mMsg->hwnd = NULL;
	mMsg->wParam = point.x;
	mMsg->lParam = point.y;
	mMsg->message = MOUSE_MSG_RELEASE;
	mMsg->time = 0;
	mMsg->pt.x = point.x;
	mMsg->pt.y = point.y;
	zMsgDispose->addMsg(mMsg);
	zMsgDispose->msgWindowsDispose();
	flag = 0;
	__super::OnLButtonUp(nFlags, point);
	this->Invalidate();
}


void CZGDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1) {
		Msg *mMsg;
		mMsg = new Msg();
		mMsg->hwnd = NULL;
		mMsg->wParam = point.x;
		mMsg->lParam = point.y;
		mMsg->message = MOUSE_MSG_MOVE;
		mMsg->time = 0;
		mMsg->pt.x = point.x;
		mMsg->pt.y = point.y;
		zMsgDispose->addMsg(mMsg);
		zMsgDispose->msgWindowsDispose();
	
	}
	__super::OnMouseMove(nFlags, point);
	this->Invalidate();
}


BOOL CZGDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return true;
	//return __super::OnEraseBkgnd(pDC);
}
