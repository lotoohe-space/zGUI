#pragma once
#ifndef _ZGD_H__
#define _ZGD_H__
#include "ZTypes.h"


/* window平台定义 */
#define _WIN32_ 1

/* 点结构体 */
typedef struct _Point {
	s32 x;
	s32 y;
}Point;
/* Window的样式 */
typedef struct _WindowsStyle {
	COLOR Color0;
	COLOR Color1;
	COLOR Color2;
	COLOR HeadColor0;
	COLOR HeadColor1;
	COLOR TitleColor;
	u32 TitleHeight;
}WindowsStyle;
/* Lable的样式 */
typedef struct _LableStyle {
	COLOR Color0;

	COLOR Color1;
	COLOR Color2;
	COLOR Color3;
}LableClssStyle;

/* 颜色模式 */
#define COLOR_MODE 24

/* 屏幕的宽高 */
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 480

/* 背景颜色 */
#define _DEF_BACKGROUND_COLOR 0x777777
/* 矩形绘制相关 */
#define SHADE_UPDOWN		 1//从上到下
#define	SHADE_LEFTRIGHT	 2//从左到右
#define	SHADE_DOWNUP		 3//从下到上
#define	SHADE_RIGHTLEFT	 4//从右到左
//获取24bit颜色的红色值
#define PIXEL888RED(pixel)      (u32)(((pixel) >> 16) & 0xff)
//获取24bit颜色的绿色值
#define PIXEL888GREEN(pixel)      (u32)(((pixel) >> 8) & 0xff)
//获取24比特颜色的蓝色值
#define PIXEL888BLUE(pixel)      (u32)((pixel) & 0xff)

/* 24bits颜色转16bits */
#define C24TO16(a,b,c) ((((a)>>3)<<11)|(((b)>>2)<<5)|((c)>>3))
/* 将3个8bits rgb颜色组合成为一个int型*/
#define CCHARTOINT(r,g,b) ((((u8)r)<<0)|(((u8)g)<<8)|((u8)b<<16))
/* 将一个整形的24位颜色转换为16位整形颜色 */
#define CI24TO16(a) ((((a>>16)&0xff)>>3)|(((a>>8)&0xff)>>2)|(((a)&0xff)>>3))
/* 将一个16位整形颜色转换为24位整形颜色 */
#define C16TO24(a) (((((a>>11)&0x1f)<<3)<<16)|((((a>>5)&0x3f)<<2)<<8)|(((a)&0x1f))<<3)


/* 最大值 */
#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif
/* 最小值 */
#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif
#endif
