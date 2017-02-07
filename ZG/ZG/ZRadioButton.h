#pragma once
#ifndef _ZRADIO_BUTTON_H__
#define _ZRADIO_BUTTON_H__
#include "ZLable.h"
class ZRadioButton :public ZLable{
private:
	/* ±»Ñ¡ÖÐ */
	u8 isSelect;
public:
	ZRadioButton(u32 x, u32 y, u32 w, u32 h, Font16 * text);
	u8 getIsSelect(void);
protected:
	void onPaint(ZGraphical * mZGraphical);
};

#endif
