
#include "stdafx.h"

#include "ZWindows.h"
#include "ZMsgDispose.h"
#include <malloc.h>
ZMsgDispose::ZMsgDispose()
{

}
void ZMsgDispose::addControlPanel(ZObject * mZObject)
{
	/* 地址是唯一的，这里用作ID */
	this->mControlList.push_front((u32)mZObject);
}

void ZMsgDispose::addMsg(Msg * msg)
{
	this->mMsgList.push_front(msg);
}
/* 分发消息给窗口 */
void ZMsgDispose::msgDistribution()
{
	/* 遍历器 */
	list<u32>::iterator iterControl;
	list<Msg*>::iterator msgControl;
	iterControl = this->mControlList.begin();
	msgControl = this->mMsgList.begin();
	/* 遍历消息 */
	for (msgControl=mMsgList.begin(); msgControl!= this->mMsgList.end(); msgControl++) {
		Msg *mMsg;
		mMsg = *msgControl;
		switch (mMsg->message) {
		case MOUSE_MSG_MOVE:
		case MOUSE_MSG_DOWN:
		case MOUSE_MSG_RELEASE:
				/* 遍历窗口 */
				for (iterControl=mControlList.begin(); iterControl!= this->mControlList.end(); iterControl++) {
					u32 temp = *iterControl;
					ZWindows *mZWN = (ZWindows *)temp;
					/* 发送消息给窗口 */
					mZWN->postMsg(mMsg);
				}//for
			break;
		}//switch
	}
}

void ZMsgDispose::msgWindowsDispose()
{
	/* 分发消息 */
	this->msgDistribution();

	/* 遍历器 */
	list<u32>::iterator wndControl;
	wndControl = this->mControlList.begin();
	/* 遍历窗口 */
	for (wndControl=mControlList.begin(); wndControl!=mControlList.end(); wndControl++) {
		u32 temp = *wndControl;
		ZWindows *mZWN = (ZWindows *)temp;
	
		mZWN->msgDispose();
	}
	list<Msg*>::iterator msgControl;
	msgControl = this->mMsgList.begin();
	/* 遍历消息 */
	for (msgControl = mMsgList.begin(); msgControl != this->mMsgList.end(); msgControl++) {
		Msg *mMsg;
		mMsg = *msgControl;
		delete(mMsg);
	}
	this->mMsgList.clear();
}
