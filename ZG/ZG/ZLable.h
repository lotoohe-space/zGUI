#pragma once
#ifndef _ZLABLE_H__
#define _ZLABLE_H__

#include "ZControlInterface.h"
#include "ZMsgDispose.h"
#include "ZPanel.h"
#include "ZGD.h"

class ZLable :public ZPanel{
protected:
	Font16 *text;
	LableClssStyle mLableClssStyle;
private:
	/* 控件的事件回调 */
	ZControlInterface *mZControlInterface;

public:
	ZLable(s32 x,s32 y,s32 w,s32 h,Font16 *text);
	void onPaint(ZGraphical *mZGraphical);
	void setText(Font16 *text);
	/* 设置字体 */
	void setFont(ZFontInterface *mZFontInterface);
	/* 处理消息 */
	void postMsg(Msg *msg);

	/* 设置事件回调 */
	void setControlEventCallBack(ZControlInterface *mZControlInterface);
};

#endif
