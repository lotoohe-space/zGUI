#pragma once
#ifndef _ZFONTINTERFACE_H__
#define _ZFONTINTERFACE_H__

#include "ZTypes.h"

/* 虚函数的接口，所有自定义的字体比较继承这个类 */
class ZFontInterface{
protected:
	u8 fontW;
	u8 fontH;
public:
	u8 getFontWidth();
	u8 getFontHeight();
	u32 getFontsWidth(Font16 *u_str);
	/* 打开字符的文件 */
	virtual u8 openFontFile(const char *filePath) = 0;
	/* 读取字符数据 */
	virtual u8 readFontData(Font16 fontCode, u8 *data) = 0;
};


#endif
