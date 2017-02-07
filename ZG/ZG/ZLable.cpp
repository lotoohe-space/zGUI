
#include "stdafx.h"
#include "ZLable.h"

void ZLable::setText(Font16 * text)
{
	this->text = text;
	this->show();
}
void ZLable::setFont(ZFontInterface * mZFontInterface)
{
	this->mZGraphical->setFont(mZFontInterface);
}

void ZLable::postMsg(Msg * msg)
{
	ZRectI mRectI;
	mRectI.left = msg->wParam;
	mRectI.top = msg->lParam;
	mRectI.w = 1;
	mRectI.h = 1;
	switch (msg->message) {
	case MOUSE_MSG_DOWN:
		if (this->mBoundary.IsIntersect(mRectI) == TRUE) {
			if (this->status == CONTROL_DOWN) { break; }
			/* 更新自己的状态 */
			this->status = CONTROL_DOWN;
			//this->show();
			if (this->mZControlInterface != NULL) {
				Msg new_msg;
				memcpy(&new_msg, msg, sizeof(Msg));
				new_msg.message = CONTROL_DOWN;
				mZControlInterface->ControlEventHandle(this, &new_msg);
			}
		}
		break;
	case MOUSE_MSG_RELEASE:
		//if (this->mBoundary.IsIntersect(mRectI) == TRUE) {
			if (this->status == CONTROL_RELEASE) { break; }
			/* 更新自己的状态 */
			this->status = CONTROL_RELEASE;
			//this->show();
			if (this->mZControlInterface != NULL) {
				Msg new_msg;
				memcpy(&new_msg, msg, sizeof(Msg));
				new_msg.message = CONTROL_RELEASE;
				mZControlInterface->ControlEventHandle(this, &new_msg);
			}
	//	}
		break;
	default:
		this->status = NULL;
	}
	if (!this->baseZPanel->getIsCustom()) {
		this->onPaint(this->mZGraphical);
	}

}
void ZLable::setControlEventCallBack(ZControlInterface * mZControlInterface)
{
	this->mZControlInterface = mZControlInterface;
}
ZLable::ZLable(s32 x, s32 y, s32 w, s32 h, Font16 * text):ZPanel(x,y,w,h)
{
	this->mBoundary.left = x;
	this->mBoundary.top = y;
	this->mBoundary.w = w;
	this->mBoundary.h = h;
	this->status = NULL;
	this->mZControlInterface = NULL;
	mLableClssStyle.Color0 = 0xffffff;
	this->text = text;
}
void ZLable::onPaint(ZGraphical * mZGraphical)
{
	s32 x, y, w, h;
	x = this->mBoundary.left;
	y = this->mBoundary.top;
	w = this->mBoundary.w;
	h = this->mBoundary.h;
	if (this->isDisplay) {
		/* 显示面板 */
		mZGraphical->drawRect(&this->mBoundary, this->backgroundColor);

		u32 fontH = this->mZGraphical->getFont()->getFontHeight();
		u32 fontsW = this->mZGraphical->getFont()->getFontsWidth(this->text);

		/* 画文字 */
		mZGraphical->drawStringEx(fontsW>(w) ? (x + 2) : ((x + 2) + ((w)-fontsW) / 2),
			(y)+((h)-fontH) / 2,w,h,
			this->text, this->mLableClssStyle.Color0);
	}
}
