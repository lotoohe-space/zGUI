#include "stdafx.h"
#include "ZFontInterface.h"

u8 ZFontInterface::getFontWidth()
{
	return u8(this->fontW);
}

u8 ZFontInterface::getFontHeight()
{
	return u8(this->fontH);
}

u32 ZFontInterface::getFontsWidth(Font16 * u_str)
{
	u32 i = 0;
	while (u_str[i]) {
		i++;
	}
	return i*this->fontW;
}
