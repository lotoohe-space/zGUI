#pragma once
#ifndef _ZRECT_H__
#define _ZRECT_H__

#include "ZGD.h"
#include "ZTypes.h"
/* 矩形类 */
class ZRectI {
public :
	/* 上边的距离 */
	s32 top;
	/* 左边的距离 */
	s32 left;
	/* 宽 */
	s32 w;
	/* 高 */
	s32 h;
	/* 面积 */
	s32 Area();
	/* 周长 */
	s32 Pir();
	/* 是否发生碰撞 */
	u8 IsIntersect(ZRectI &mZRectI);
	/* 获得相交的矩形 */
	void getIntersectArea(ZRectI & mZRectI0,  ZRectI &resultRectI);
private:
protected:
};


#endif
