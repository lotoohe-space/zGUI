#pragma once
#ifndef _ZPAINT_H__
#define _ZPAINT_H__
#include "ZTypes.h"


class ZPaint {
protected:
public:
	void setLineWidth(int lineWidth);
	void setColor(int color);
	u32 getColor();
	u32 getLineWidth();
private:
	/* �߿� */
	u32 lineWidth;
	/* ��ɫ */
	u32 color;
};


#endif
