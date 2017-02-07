#pragma once
#ifndef _ZTYPES_H__
#define _ZTYPES_H__

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
typedef char s8;
typedef volatile int vs32;
typedef volatile short vs16;
typedef volatile char vs8;
typedef volatile unsigned char vu8;
typedef volatile unsigned short vu16;
typedef volatile unsigned int vu32;
typedef unsigned long long u64; 
typedef unsigned short Font16;
#define COLOR unsigned int
#define TRUE 1
#define FALSE 0
#ifndef NULL
#define NULL 0X00
#endif
#endif