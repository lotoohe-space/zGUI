#pragma once
#ifndef _ZGD_H__
#define _ZGD_H__
#include "ZTypes.h"


/* windowƽ̨���� */
#define _WIN32_ 1

/* ��ṹ�� */
typedef struct _Point {
	s32 x;
	s32 y;
}Point;
/* Window����ʽ */
typedef struct _WindowsStyle {
	COLOR Color0;
	COLOR Color1;
	COLOR Color2;
	COLOR HeadColor0;
	COLOR HeadColor1;
	COLOR TitleColor;
	u32 TitleHeight;
}WindowsStyle;
/* Lable����ʽ */
typedef struct _LableStyle {
	COLOR Color0;

	COLOR Color1;
	COLOR Color2;
	COLOR Color3;
}LableClssStyle;

/* ��ɫģʽ */
#define COLOR_MODE 24

/* ��Ļ�Ŀ�� */
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 480

/* ������ɫ */
#define _DEF_BACKGROUND_COLOR 0x777777
/* ���λ������ */
#define SHADE_UPDOWN		 1//���ϵ���
#define	SHADE_LEFTRIGHT	 2//������
#define	SHADE_DOWNUP		 3//���µ���
#define	SHADE_RIGHTLEFT	 4//���ҵ���
//��ȡ24bit��ɫ�ĺ�ɫֵ
#define PIXEL888RED(pixel)      (u32)(((pixel) >> 16) & 0xff)
//��ȡ24bit��ɫ����ɫֵ
#define PIXEL888GREEN(pixel)      (u32)(((pixel) >> 8) & 0xff)
//��ȡ24������ɫ����ɫֵ
#define PIXEL888BLUE(pixel)      (u32)((pixel) & 0xff)

/* 24bits��ɫת16bits */
#define C24TO16(a,b,c) ((((a)>>3)<<11)|(((b)>>2)<<5)|((c)>>3))
/* ��3��8bits rgb��ɫ��ϳ�Ϊһ��int��*/
#define CCHARTOINT(r,g,b) ((((u8)r)<<0)|(((u8)g)<<8)|((u8)b<<16))
/* ��һ�����ε�24λ��ɫת��Ϊ16λ������ɫ */
#define CI24TO16(a) ((((a>>16)&0xff)>>3)|(((a>>8)&0xff)>>2)|(((a)&0xff)>>3))
/* ��һ��16λ������ɫת��Ϊ24λ������ɫ */
#define C16TO24(a) (((((a>>11)&0x1f)<<3)<<16)|((((a>>5)&0x3f)<<2)<<8)|(((a)&0x1f))<<3)


/* ���ֵ */
#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif
/* ��Сֵ */
#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif
#endif
