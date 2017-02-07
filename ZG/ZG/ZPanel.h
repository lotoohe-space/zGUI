#pragma once
#ifndef _ZPANEL_H__
#define _ZPANEL_H__


#include "ZFontInterface.h"
#include "ZGraphical.h"
#include "ZObject.h"
#include "ZTypes.h"


#include "ZMsgDispose.h"
class ZPanel :public ZObject{
public :
	ZPanel(int left,int top,int w,int h);
	~ZPanel();
	void setDispaly(u8 isDisplay);
	void show();
	void setBackgroundColor(COLOR backgroundColor);
	virtual void setLocation(s32 x, s32 y);
	virtual void getLocation(Point &mPoint);
	virtual void setFont(ZFontInterface *ZFontInterface) = 0;
	ZRectI* getBackBoundary();
	ZGraphical * getGraphical();
	virtual void setEnable(u8 isEnable);
	/* 处理消息 */
	virtual void postMsg(Msg *msg);
	virtual void msgDispose();
	/* 父容器操作 */
	ZPanel * getBasePanel();
	void setBasePanel(ZPanel *mZPanel);
	u8 getIsCustom(void);
private:

protected:
	/* 父容器 */
	ZPanel *baseZPanel;
	/* 控件的状态 点击 松开 空闲(NULL)*/
	u32 status;
	/* 控件是否被使能 */
	u8 isEnable;
	/* 绘图的类 */
	ZGraphical *mZGraphical;
	/* 是否显示 */
	u8 isDisplay;
	/* 窗口空白 */
	u8 isCustom;
	/* 背景颜色 */
	COLOR backgroundColor;
	/* 上次一次的位置以及大小 */
	ZRectI backBoundary;
	void onPaint(ZGraphical *mZGraphical);
	
};


#endif
