#pragma once

#include "ZMsgDispose.h"
#include "ZButton.h"
#include "ZPanel.h"
#include "WindowsEventInterface.h"
#include "ZGD.h"
#include <list>
using namespace std;

enum ZWindowsStatur {
	NONE,MOVE
};


/* ������Ķ��� */
class ZWindows :public ZPanel{
private:
	/* �û��ı����ַ� */
	Font16 *text;
	/* ���ڱ�������λ�� */
	ZRectI titleRect;

	/* ��Ϣ���б� */
	list<Msg*> mMsgList;
	/* ����ڲ��Ŀؼ� */
	list<ZPanel*> mZPanelList;


	/* �����ϵ�Ĭ�ϰ�ť */
	ZButton* closeButton;
	/* Windows����ʽ */
	WindowsStyle mWindowsStyle;

	/* �¼��ص� */
	WindowsEventInterface *mWindowsEventDispose;

	
	/* ��һ��ˢ�� */
	u8 firstPaint;

	/* ����״̬ */
	ZWindowsStatur isRunStatus;

	/* ��������һ���ؼ���λ�� */
	void showControl(ZPanel *mZPane);
protected:
	void loadWindow();
	/*  ������ƺ��� */
	void onPaint(ZGraphical *mZGraphical);
public :
	ZWindows(s32 x, s32 y, s32 w, s32 h, Font16* text);
	~ZWindows();
	/* �򴰿ڷ�����Ϣ */
	void postMsg(Msg* msg);
	/* �����ڵ���Ϣ������һϵ�е��¼� */
	/* ���������ѭ������ */
	void msgDispose();
	/* ���ô����¼� */
	void setWindowEventCallBack(WindowsEventInterface *mWindowsEventDispose);
	/* �������� */
	void setFont(ZFontInterface *mZFontInterface);
	/* ���һ���ؼ� */
	void add(ZPanel *mZPanel);
	/* ���ô���Ϊ����ģʽ */
	void setCustom(u8 isCustom);
	/* ��ȡ�������� */
	Font16* getText(void);
};
