
// ZGDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CZGDlg 对话框



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


// CZGDlg 消息处理程序
#include <conio.h>
BOOL CZGDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	AllocConsole();

	mZGDlg = this;
	// TODO: 在此添加额外的初始化代码

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
	
	mZLable = new ZLable(0, 60, 100, 20, (u16*)L"你好");
	mZLable->setControlEventCallBack(this);

	mZButton = new ZButton(16, 16, 100, 30, (u16*)L"你好");
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
	//mZGraphical->drawStringEx(0, 0,50,50, (u16*)L"你好，\n世界。。", 0xffffff);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CZGDlg::OnPaint()
{
	//CPaintDC dc(this); // 用于绘制的设备上下文

	//CDC *pDC = &dc;
	//if (IsIconic())
	//{
	//	CPaintDC dc(this); // 用于绘制的设备上下文

	//	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

	//	// 使图标在工作区矩形中居中
	//	int cxIcon = GetSystemMetrics(SM_CXICON);
	//	int cyIcon = GetSystemMetrics(SM_CYICON);
	//	CRect rect;
	//	GetClientRect(&rect);
	//	int x = (rect.Width() - cxIcon + 1) / 2;
	//	int y = (rect.Height() - cyIcon + 1) / 2;

	//	// 绘制图标
	//	dc.DrawIcon(x, y, m_hIcon);
	//}
	//else
	//{
	//	CDialogEx::OnPaint();
		//CDC MemDC; //首先定义一个显示设备对象 
		//CBitmap MemBitmap;//定义一个位图对象 
		//				  //随后建立与屏幕显示兼容的内存显示设备 
		//MemDC.CreateCompatibleDC(NULL); //这时还不能绘图，因为没有地方画 ^_^ 
		//								//下面建立一个与屏幕显示兼容的位图，至于位图的大小嘛，可以用窗口的大小 
		//MemBitmap.CreateCompatibleBitmap(pDC, 240, 320); //将位图选入到内存显示设备中 
		//														//只有选入了位图的内存显示设备才有地方绘图，画到指定的位图上 
		//CBitmap *pOldBit = MemDC.SelectObject(&MemBitmap);
		////先用背景色将位图清除干净，这里我用的是白色作为背景 
		////你也可以用自己应该用的颜色 
		//MemDC.FillSolidRect(0, 0, 240, 320, RGB(255, 255, 255));
		////绘图 
		//for (int i = 0; i < 240; i++) {
		//	for (int j = 0; j < 320; j++) {
		//		MemDC.SetPixel(i, j, screenBuffer[i][j]);
		//	}
		//}
		////将内存中的图拷贝到屏幕上进行显示 
		//pDC->BitBlt(0, 0, 240, 320, &MemDC, 0, 0, SRCCOPY);
		////绘图完成后的清理 
		//MemBitmap.DeleteObject();
		//MemDC.DeleteDC();

		//CPaintDC dc(this); // 用于绘制的设备上下文
		//dc.Draw3dRect(5, 5, 200,200,0x00000000, 0x00ff00ff);
	
	//}
	CPaintDC dc(this); // device context for painting  
	CRect rect;//设计整个绘图区域大小的矩形 
	CDC *pDC;
	CDC MemDC;   //创建兼容的内存DC  
	CBitmap MemBitmap;  //创立画布之后由指针获取当前控件的DC   
	pDC = GetDC();
	GetClientRect(&rect);   //获取客户端区域大小  
	pDC = GetDC();
	//选定与客户端区域大小相同的位置创建绘制位图  
	MemDC.CreateCompatibleDC(pDC);
	MemBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	MemDC.SelectObject(&MemBitmap);   //将位图选进内存中  
	//MemDC.SelectObject(&pen);
	MemDC.FillSolidRect(rect, RGB(255, 255, 255));

	//填充颜色
	for (int i = 0; i < SCREEN_WIDTH; i++) {
		for (int j = 0; j < SCREEN_HEIGHT; j++) {
			MemDC.SetPixel(i, j, screenBuffer[i][j]);
		}
	}
	//然后开始讲内存中已经绘制好的一次性全部呈现到屏幕上  
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &MemDC, 0, 0, SRCCOPY);


	//内存复位
	MemDC.SelectObject(MemBitmap);
}




//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
		//mZLable->setText((u16*)L"变一下..");
		//mZWindow = new ZWindows(msg->wParam, msg->lParam, 200, 200, (u16*)L"你好世界你好世界你好世界你好世界");
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
		mZLable->setText((u16*)L"变一下..");
	}
	else {
		//MessageBox(L"up", L"msg", 0);
	}
}


void CZGDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return true;
	//return __super::OnEraseBkgnd(pDC);
}
