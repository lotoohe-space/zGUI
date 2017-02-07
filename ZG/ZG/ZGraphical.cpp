#include "stdafx.h"
#include "ZGraphical.h"
#include "ZTypes.h"
#include "ZRect.h"



#include "ZGDlg.h"
CZGDlg *mZGDlg;
ZGraphical::ZGraphical()
{
	this->mZFontInterface = NULL;
	this->mZPaint = NULL;
	this->boundRect.left = 0;
	this->boundRect.top = 0;
	this->boundRect.w = SCREEN_WIDTH;
	this->boundRect.h = SCREEN_HEIGHT;
}
ZRectI * ZGraphical::getDrawBound()
{
	return &this->boundRect;
}
void ZGraphical::setDrawBound(s32 x, s32 y, s32 w, s32 h)
{
	this->boundRect.left = x;
	this->boundRect.top = y;
	this->boundRect.w = w;
	this->boundRect.h = h;
}
void ZGraphical::setPaint(ZPaint * mZPaint)
{
	this->mZPaint = mZPaint;
}

void ZGraphical::setFont(ZFontInterface * mZFontInterface)
{
	this->mZFontInterface = mZFontInterface;
}

ZFontInterface * ZGraphical::getFont()
{
	return this->mZFontInterface;
}

void ZGraphical::drawLine(s32 x0, s32 y0, s32 x1, s32 y1, COLOR color)
{
	u16 t;
	int xerr = 0, yerr = 0, delta_x, delta_y, distance;
	int incx, incy, uRow, uCol;
	delta_x = x1 - x0; //计算坐标增量 
	delta_y = y1 - y0;
	uRow = x0;
	uCol = y0;
	if (delta_x>0)incx = 1; //设置单步方向 
	else if (delta_x == 0)incx = 0;//垂直线 
	else { incx = -1; delta_x = -delta_x; }
	if (delta_y>0)incy = 1;
	else if (delta_y == 0)incy = 0;//水平线 
	else { incy = -1; delta_y = -delta_y; }
	if (delta_x>delta_y)distance = delta_x; //选取基本增量坐标轴 
	else distance = delta_y;
	for (t = 0; t <= distance + 1; t++)//画线输出 
	{
		this->setPixel(uRow, uCol, color);//画点 
		xerr += delta_x;
		yerr += delta_y;
		if (xerr>distance)
		{
			xerr -= distance;
			uRow += incx;
		}
		if (yerr>distance)
		{
			yerr -= distance;
			uCol += incy;
		}
	}
}

void ZGraphical::drawRect(s32 x, s32 y, s32 w, s32 h, COLOR color)
{
	for (int i = x; i < x + w; i++) {
		for (int j = y; j < y + h; j++) {
			this->setPixel(i, j, color);
		}
	}
}
void ZGraphical::drawRect(ZRectI * ZRectI,COLOR color)
{
	drawRect(ZRectI->left, ZRectI->top, ZRectI->w, ZRectI->h, color);
}
void ZGraphical::drawEdgeRect(s32 x, s32 y, s32 w, s32 h, COLOR color)
{
	if (w == 0 && h == 0) { return; }
	this->drawLine(x, y, x, y + h, color);
	this->drawLine(x, y, x+w, y , color);
	this->drawLine(x+w, y, x+w, y + h, color);
	this->drawLine(x, y+h, x+w, y + h, color);
}
void ZGraphical::drawGradientRect(int x, int y, int w, int h, COLOR pixelA, COLOR pixelB, u8 mode)
{
	s16 i, j, t;
	COLOR AR, AG, AB, BR, BG, BB;

	AR = PIXEL888RED(pixelA);
	AB = PIXEL888BLUE(pixelA);
	AG = PIXEL888GREEN(pixelA);

	BR = PIXEL888RED(pixelB);
	BB = PIXEL888BLUE(pixelB);
	BG = PIXEL888GREEN(pixelB);

	BR -= AR;
	BG -= AG;
	BB -= AB;
	switch (mode)
	{
	case SHADE_UPDOWN:
		t = x + w - 1;
		for (i = 0; i<h; i++)
			this->drawLine(x, y + i, t, y + i, CCHARTOINT((u8)(AR + BR*i / h), (u8)(AG + BG*i / h), (u8)(AB + BB*i / h)));
		return;
	case SHADE_DOWNUP:
		t = x + w - 1;
		for (i = h - 1, j = 0; i >= 0; i--, j++)
			this->drawLine(x, y + i, t, y + i, CCHARTOINT((u8)(AR + BR*j / h), (u8)(AG + BG*j / h), (u8)(AB + BB*j / h)));
		return;
	case SHADE_LEFTRIGHT:
		t = y + h - 1;
		for (i = 0; i<w; i++)
			this->drawLine(x + i, y, x + i, t, CCHARTOINT((u8)(AR + BR*i / w), (u8)(AG + BG*i / w), (u8)(AB + BB*i / w)));
		return;
	case SHADE_RIGHTLEFT:
		t = y + h - 1;
		for (i = w - 1, j = 0; i >= 0; i--, j++)
			this->drawLine(x + i, y, x + i, t, CCHARTOINT((u8)(AR + BR*j / w), (u8)(AG + BG*j / w), (u8)(AB + BB*j / w)));
		return;
	}

}
void ZGraphical::drawCircle(s32 x0, s32 y0, s32 r, COLOR color)
{
	int a, b;
	int di;
	a = 0; b = r;
	di = 3 - (r << 1);             //判断下个点位置的标志
	while (a <= b)
	{
		this->setPixel(x0 + a, y0 - b, color);             //5
		this->setPixel(x0 + b, y0 - a, color);             //0           
		this->setPixel(x0 + b, y0 + a, color);             //4               
		this->setPixel(x0 + a, y0 + b, color);             //6 
		this->setPixel(x0 - a, y0 + b, color);             //1       
		this->setPixel(x0 - b, y0 + a, color);
		this->setPixel(x0 - a, y0 - b, color);             //2             
		this->setPixel(x0 - b, y0 - a, color);             //7     	         
		a++;
		//使用Bresenham算法画圆     
		if (di<0)di += 4 * a + 6;
		else
		{
			di += 10 + 4 * (a - b);
			b--;
		}
	}
}
u8 ZGraphical::drawChar(s32 x, s32 y, const Font16 ch, COLOR color)
{
	/* 存放临时的字符数据 */
	u8 *charDataTemp;
	u8 i, j, w, h;
	if (mZFontInterface == NULL) {
		return FALSE;
	}
	w = mZFontInterface->getFontWidth();
	h = mZFontInterface->getFontHeight();
	charDataTemp = new u8[w*h/8];
	if (mZFontInterface->readFontData(ch, charDataTemp) == FALSE) {
		return FALSE;
	}
	for (i = 0; i<h; i++) {
		Font16 _temp_c;
		_temp_c = (Font16)(charDataTemp[2 * i]) << 8 | (Font16)(charDataTemp[2 * i + 1]);
		for (j = 0; j<w; j++) {
			if (((_temp_c >> j) & 0x01) == 0x01) {
				/* 画字符的点 */
				this->setPixel(x + h - 1 - j, y + i, color); 
			}
		}
	}
	delete[] charDataTemp;
	return TRUE;
}
u8 ZGraphical::drawString(s32 x, s32 y, const Font16 * text, COLOR color)
{
	u32 i;
	if (this->mZFontInterface == NULL) {
		return FALSE;
	}
	for (i = 0; text[i]; i++) {
		if (text[i] == '\n') {
			y += this->mZFontInterface->getFontHeight();
		}
		else {
			this->drawChar(x, y, text[i], color);
			x += this->mZFontInterface->getFontWidth();
		}
	}
	return u8(TRUE);
}
u8 ZGraphical::drawStringEx(s32 x, s32 y, s32 ExW, s32 ExH, const Font16 * text, COLOR color)
{
	ZRectI mRectI,resultRectI;
	mRectI.left = x;
	mRectI.top = y;
	mRectI.w = ExW;
	mRectI.h = ExH;
	mRectI.getIntersectArea(*this->getDrawBound(), resultRectI);
	///* 求相交矩形 */
	s32 x_temp = this->getDrawBound()->left;
	s32 y_temp = this->getDrawBound()->top;
	s32 w_temp = this->getDrawBound()->w;
	s32 h_temp = this->getDrawBound()->h;
	/* 根据相交矩形进行设置 */
	this->setDrawBound(resultRectI.left, resultRectI.top, resultRectI.w, resultRectI.h);
	if (this->drawString(x, y, text, color) == FALSE) {
		this->setDrawBound(x_temp, y_temp, w_temp, h_temp);
		return FALSE;
	}
	this->setDrawBound(x_temp, y_temp, w_temp, h_temp);
	return u8(TRUE);
}
/*
	颜色转换为透明的颜色值
*/
COLOR ZGraphical::calTransparentPixel(COLOR color0, COLOR color1, u8 transparent)
{
	COLOR  r, g, b;
	COLOR  r0, g0, b0;
	COLOR rgb;
#if COLOR_MODE== 24
	b = (color0 >> 0) & 0xff;
	g = (color0 >> 8) & 0xff;
	r = (color0 >> 16) & 0xff;
	b0 = (color1 >> 0) & 0xff;
	g0 = (color1 >> 8) & 0xff;
	r0 = (color1 >> 16) & 0xff;
#else
	#if  COLOR_MODE ==16
		b = (color0 >> 0) & 0x1f;
		g = (color0 >> 5) & 0x3f;
		r = (color0 >> 11) & 0x1f;
		b0 = (color1 >> 0) & 0x1f;
		g0 = (color1 >> 5) & 0x3f;
		r0 = (color1 >> 11) & 0x1f;
	#endif
#endif
	b *= transparent;g *= transparent;r *= transparent;
	b0 *= (255 - transparent);g0*= (255 - transparent);r0 *= (255 - transparent);
	b = b + b0;
	g = g + g0;
	r = r + r0;
	b >>= 8;
	g >>= 8;
	r >>= 8;
#if COLOR_MODE== 24
		rgb = (b << 16) | (g << 8) | (r << 0);
#else
	#if  COLOR_MODE ==16
		rgb = (b << 0) | (g << 5) | (r << 11);
	#endif
#endif
	return(rgb);
}
void ZGraphical::setPixel(s32 x, s32 y, COLOR color)
{
	if (x >= this->boundRect.left&&y >= this->boundRect.top&&
		x < this->boundRect.left + this->boundRect.w&&
		y < this->boundRect.top + this->boundRect.h
		) {
		mZGDlg->setPixel(x, y, color);
	}
	
}

void ZGraphical::setPixel(s32 x, s32 y, COLOR color, u8 transparent)
{
	COLOR c_temp;
	c_temp = this->getPixel(x, y);
	this->setPixel(x, y, calTransparentPixel(c_temp, color, transparent));
}

COLOR ZGraphical::getPixel(s32 x, s32 y)
{
	return mZGDlg->getPixel(x,y);
}
