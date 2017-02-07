
// ZGDlg.h : 头文件
//

#pragma once

#include "ZButton.h"
#include "ZFont0.h"
#include "ZWindows.h"
#include "ZLable.h"
#include "ZMsgDispose.h"
#include "WindowsEventInterface.h"
#include "ZControlInterface.h"
#include "ZPanel.h"

// CZGDlg 对话框
class CZGDlg : public CDialogEx,public WindowsEventInterface,public ZControlInterface
{
// 构造
public:
	u8 flag;
	ZWindows *mZWindow;
	ZFont0 *mZFont0;
	ZPanel *mZPanel;
	ZLable *mZLable;
	ZButton *mZButton;
	/*  输入的缓存 */
	unsigned int screenBuffer[SCREEN_WIDTH][SCREEN_HEIGHT];
	CZGDlg(CWnd* pParent = NULL);	// 标准构造函数
	void setPixel(int x, int y, unsigned int color);
	unsigned int getPixel(int x, int y);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZG_DIALOG };
#endif

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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void windowsEventDispose(Msg *msg);
	void ControlEventHandle(ZPanel *mZPanel, Msg* msg);
	ZMsgDispose *zMsgDispose;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
