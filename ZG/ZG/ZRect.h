#pragma once
#ifndef _ZRECT_H__
#define _ZRECT_H__

#include "ZGD.h"
#include "ZTypes.h"
/* ������ */
class ZRectI {
public :
	/* �ϱߵľ��� */
	s32 top;
	/* ��ߵľ��� */
	s32 left;
	/* �� */
	s32 w;
	/* �� */
	s32 h;
	/* ��� */
	s32 Area();
	/* �ܳ� */
	s32 Pir();
	/* �Ƿ�����ײ */
	u8 IsIntersect(ZRectI &mZRectI);
	/* ����ཻ�ľ��� */
	void getIntersectArea(ZRectI & mZRectI0,  ZRectI &resultRectI);
private:
protected:
};


#endif
