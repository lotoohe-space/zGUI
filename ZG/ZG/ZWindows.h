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


/* 窗口类的定义 */
class ZWindows :public ZPanel{
private:
	/* 用户的标题字符 */
	Font16 *text;
	/* 窗口标题栏的位置 */
	ZRectI titleRect;

	/* 消息的列表 */
	list<Msg*> mMsgList;
	/* 存放内部的控件 */
	list<ZPanel*> mZPanelList;


	/* 窗口上的默认按钮 */
	ZButton* closeButton;
	/* Windows的样式 */
	WindowsStyle mWindowsStyle;

	/* 事件回调 */
	WindowsEventInterface *mWindowsEventDispose;

	
	/* 第一次刷新 */
	u8 firstPaint;

	/* 窗口状态 */
	ZWindowsStatur isRunStatus;

	/* 重新设置一个控件的位置 */
	void showControl(ZPanel *mZPane);
protected:
	void loadWindow();
	/*  界面绘制函数 */
	void onPaint(ZGraphical *mZGraphical);
public :
	ZWindows(s32 x, s32 y, s32 w, s32 h, Font16* text);
	~ZWindows();
	/* 向窗口发送消息 */
	void postMsg(Msg* msg);
	/* 处理窗口的消息，产生一系列的事件 */
	/* 这个函数被循环调用 */
	void msgDispose();
	/* 设置窗口事件 */
	void setWindowEventCallBack(WindowsEventInterface *mWindowsEventDispose);
	/* 设置字体 */
	void setFont(ZFontInterface *mZFontInterface);
	/* 添加一个控件 */
	void add(ZPanel *mZPanel);
	/* 设置窗口为定制模式 */
	void setCustom(u8 isCustom);
	/* 获取窗口文字 */
	Font16* getText(void);
};
