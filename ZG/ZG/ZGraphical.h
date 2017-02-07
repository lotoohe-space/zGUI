#pragma once
#ifndef _ZGRAPHICAL_H__
#define _ZGRAPHICAL_H__
#include "ZFontInterface.h"
#include "ZPaint.h"
#include "ZRect.h"
class ZGraphical {
public:
	ZGraphical();
	ZRectI* getDrawBound();
	/* 设置绘图的窗口限定 */
	void setDrawBound(s32 x, s32 y, s32 w, s32 h);
	void setPaint(ZPaint *mZPaint);
	/* 字体设置函数 */
	void setFont(ZFontInterface *mZFontInterface);
	ZFontInterface* getFont();
	/* 线绘制相关函数 */
	void drawLine(s32 x0, s32 y0, s32 x1, s32 y1, COLOR color);
	void drawRect(s32 x, s32 y, s32 w, s32 h, COLOR color);
	void drawRect(ZRectI *ZRectI, COLOR color);
	void drawEdgeRect(s32 x, s32 y, s32 w, s32 h, COLOR color);
	void drawGradientRect(int x, int y, int w, int h, COLOR pixelA, COLOR pixelB, u8 mode);
	void drawCircle(s32 x0, s32 y0, s32 r, COLOR color);
	/* 字符绘制相关函数 */
	u8 drawChar(s32 x, s32 y, const Font16 ch, COLOR color);
	u8 drawString(s32 x, s32 y, const Font16 *text, COLOR color);
	u8 drawStringEx(s32 x, s32 y, s32 ExW, s32 ExH, const Font16 *text, COLOR color);
	
	static COLOR calTransparentPixel(COLOR color0, COLOR color1, u8 transparent);
	void setPixel(s32 x, s32 y, COLOR color);
	void setPixel(s32 x, s32 y, COLOR color, u8 transparent);
	COLOR getPixel(s32 x, s32 y);
protected:
	
private:
	/* 绘图的属性 */
	ZPaint *mZPaint;
	/* 设置字体 */
	ZFontInterface *mZFontInterface;
	/* 设置绘图的边界 */
	ZRectI boundRect;
};



#endif
