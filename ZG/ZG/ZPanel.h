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
	/* ������Ϣ */
	virtual void postMsg(Msg *msg);
	virtual void msgDispose();
	/* ���������� */
	ZPanel * getBasePanel();
	void setBasePanel(ZPanel *mZPanel);
	u8 getIsCustom(void);
private:

protected:
	/* ������ */
	ZPanel *baseZPanel;
	/* �ؼ���״̬ ��� �ɿ� ����(NULL)*/
	u32 status;
	/* �ؼ��Ƿ�ʹ�� */
	u8 isEnable;
	/* ��ͼ���� */
	ZGraphical *mZGraphical;
	/* �Ƿ���ʾ */
	u8 isDisplay;
	/* ���ڿհ� */
	u8 isCustom;
	/* ������ɫ */
	COLOR backgroundColor;
	/* �ϴ�һ�ε�λ���Լ���С */
	ZRectI backBoundary;
	void onPaint(ZGraphical *mZGraphical);
	
};


#endif
