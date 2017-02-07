#include "stdafx.h"

#include "ZGD.h"
#include "ZRect.h"
#include "ZTypes.h"
/*  面积 */
s32 ZRectI::Area()
{
	return w*h;
}
/* 周长 */
s32 ZRectI::Pir()
{
	return w + w + h + h;
}
/* 检测是否相交了 */
u8 ZRectI::IsIntersect(ZRectI &mZRectI)
{
	if (this->left > mZRectI.left + mZRectI.w) {
		return FALSE;
	}
	else if (this->top > mZRectI.top + mZRectI.h) {
		return FALSE;
	}
	else if (this->left + this->w < mZRectI.left) {
		return FALSE;
	}
	else if (this->top + this->h < mZRectI.top) {
		return FALSE;
	}
	return TRUE;
}

void ZRectI::getIntersectArea(ZRectI & mZRectI0,ZRectI &resultRectI)
{
	s32 x, y;
	s32 endx, endy;
	s32 x_temp = mZRectI0.left;
	s32 y_temp = mZRectI0.top;
	s32 w_temp = mZRectI0.w;
	s32 h_temp = mZRectI0.h;

	x = max(x_temp, this->left);
	y = max(y_temp, this->top);
	endx = min(x_temp + w_temp , this->left + this->w );
	endy = min(y_temp + h_temp, this->top + this->h );
	resultRectI.left = x;
	resultRectI.top = y;
	resultRectI.w = endx - x;
	resultRectI.h = endy - y;
}
