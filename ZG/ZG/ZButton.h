#pragma once
#ifndef _ZBUTTON_H__
#define _ZBUTTON_H__

#include "ZLable.h"
#include "ZTypes.h"
class ZButton :public ZLable {
public :
	ZButton(u32 x,u32 y,u32 w,u32 h,Font16 *text);
	void onPaint(ZGraphical * mZGraphical);
};

#endif
