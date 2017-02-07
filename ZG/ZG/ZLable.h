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
	/* �ؼ����¼��ص� */
	ZControlInterface *mZControlInterface;

public:
	ZLable(s32 x,s32 y,s32 w,s32 h,Font16 *text);
	void onPaint(ZGraphical *mZGraphical);
	void setText(Font16 *text);
	/* �������� */
	void setFont(ZFontInterface *mZFontInterface);
	/* ������Ϣ */
	void postMsg(Msg *msg);

	/* �����¼��ص� */
	void setControlEventCallBack(ZControlInterface *mZControlInterface);
};

#endif
