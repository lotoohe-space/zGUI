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
	/* Ïß¿í */
	u32 lineWidth;
	/* ÑÕÉ« */
	u32 color;
};


#endif
