#pragma once

#include "ZGraphical.h"
#include "ZRect.h"
#include "ZTypes.h"
#include "ZGD.h"

class ZObject {
protected:
	/* 组件的边界 */
	ZRectI mBoundary;
private:
	
public:
	/* 公共的函数 */
	ZRectI *getBoundary();
	void setTop(s32 top);
	void setLeft(s32 left);
	void setW(s32 w);
	void setH(s32 h);
	void setBoundary(ZRectI &mBoundary);
	virtual  void onPaint(ZGraphical * mZGraphical) = 0;
	ZObject();
	ZObject(ZRectI &mBoundary);
	ZObject(s32 top, s32 left, s32 w, s32 h);
	~ZObject();
};




