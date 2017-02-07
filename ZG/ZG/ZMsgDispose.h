#pragma once

#include "ZObject.h"
#include "ZTypes.h"
#include <list>   
using namespace std;
/* 消息事件的定义 */
#define MOUSE_MSG_DOWN 0x0200 //鼠标按下
#define MOUSE_MSG_RELEASE 0x0201 //鼠标松开
#define MOUSE_MSG_MOVE    0x0204 //鼠标移动
#define CONTROL_DOWN 0x0202 //控件按下
#define CONTROL_RELEASE 0x0203//控件释放


/* 消息的结构体 */
typedef struct _Msg {
	u32 hwnd;          // 接受该消息的窗口句柄
	u32 message;         // 消息常量标识符，也就是我们通常所说的消息号 
	u32 wParam;     // 32位消息的特定附加信息，确切含义依赖于消息值 
	u32 lParam;       // 32位消息的特定附加信息，确切含义依赖于消息值 
	u64 time;         // 消息创建时的时间 
	Point pt;             // 消息创建时的鼠标/光标在屏幕坐标系中的位置 
}Msg;


class ZMsgDispose {
protected:

public :
	ZMsgDispose();
	/* 注册一个控件 */
	void addControlPanel(ZObject *mZObject);
	/* 添加一个消息 */
	void addMsg(Msg *msg);
	/*  分发消息-->循环调用 */
	void msgDistribution();
	/* 整个GUI消息的处理函数,在这里面会调用所有窗口的消息处理函数*/
	void msgWindowsDispose();
private:
	/* 存放gui在所有的控件 */
	list<u32>  mControlList;
	/* 消息列表 */
	list<Msg*>  mMsgList;

};

