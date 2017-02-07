#include "stdafx.h"

#include "ZPaint.h"
#include "ZTypes.h"

void ZPaint::setLineWidth(int lineWidth)
{
	this->lineWidth = lineWidth;
}

void ZPaint::setColor(int color)
{
	this->color = color;
}

u32 ZPaint::getColor()
{
	return u32(this->color);
}

u32 ZPaint::getLineWidth()
{
	return u32(this->lineWidth);
}
