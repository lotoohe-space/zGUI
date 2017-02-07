#pragma once
#ifndef _ZFONTINTERFACE_H__
#define _ZFONTINTERFACE_H__

#include "ZTypes.h"

/* �麯���Ľӿڣ������Զ��������Ƚϼ̳������ */
class ZFontInterface{
protected:
	u8 fontW;
	u8 fontH;
public:
	u8 getFontWidth();
	u8 getFontHeight();
	u32 getFontsWidth(Font16 *u_str);
	/* ���ַ����ļ� */
	virtual u8 openFontFile(const char *filePath) = 0;
	/* ��ȡ�ַ����� */
	virtual u8 readFontData(Font16 fontCode, u8 *data) = 0;
};


#endif
