
// ZGDlg.h : ͷ�ļ�
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

// CZGDlg �Ի���
class CZGDlg : public CDialogEx,public WindowsEventInterface,public ZControlInterface
{
// ����
public:
	u8 flag;
	ZWindows *mZWindow;
	ZFont0 *mZFont0;
	ZPanel *mZPanel;
	ZLable *mZLable;
	ZButton *mZButton;
	/*  ����Ļ��� */
	unsigned int screenBuffer[SCREEN_WIDTH][SCREEN_HEIGHT];
	CZGDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void setPixel(int x, int y, unsigned int color);
	unsigned int getPixel(int x, int y);
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZG_DIALOG };
#endif

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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void windowsEventDispose(Msg *msg);
	void ControlEventHandle(ZPanel *mZPanel, Msg* msg);
	ZMsgDispose *zMsgDispose;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
