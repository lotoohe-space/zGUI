
#include "stdafx.h"

#include "ZFont0.h"

ZFont0::ZFont0()
{
	fontH = 16;
	fontW = 16;
	this->filePath = "E:/vs2015/ZG/ZG/system.DZK";
	openFontFile(this->filePath);
}

ZFont0::ZFont0(u8 w, u8 h,char *filePath)
{
	fontW = w;
	fontH = h;
	this->filePath = filePath;
}

u8 ZFont0::openFontFile(const char * filePath)
{
	int res = fopen_s(&mFIL, filePath, "rb");
	if (res == 1) {
		return FALSE;
	}
	return TRUE;
}

u8 ZFont0::readFontData(Font16 fontCode, u8 * data)
{
	if (mFIL == NULL) {
		return FALSE;
	}
	/* ¶ÁÈ¡×Ö·ûÊý¾Ý */
	fseek(mFIL,  fontCode*(fontW*fontH / 8),SEEK_SET );
	fread(data, (fontW*fontH / 8), 1, mFIL);
	return TRUE;
}
