#pragma once
#ifndef _ZFONT0_H__
#define _ZFONT0_H__
#include "ZFontInterface.h"
#include "ZTypes.h"
#include "ZGD.h"
#include <cstdio>
class ZFont0 :public ZFontInterface {
private:
	FILE *mFIL;
	char *filePath ;
public:
	ZFont0();
	ZFont0(u8 w, u8 h, char *filePath);
	/* 打开字符的文件 */
	u8 openFontFile(const char *filePath);
	/* 读取字符数据 */
	u8 readFontData(Font16 fontCode, u8 *data);
};
#endif
