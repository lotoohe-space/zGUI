
#include "stdafx.h"
#include "ZPanel.h"



ZPanel::ZPanel(int left, int top, int w, int h)
{
	this->isDisplay = TRUE;
	this->mBoundary.left = backBoundary .left = left;
	this->mBoundary.top = backBoundary.top = top;
	this->mBoundary.w = backBoundary.w = w;
	this->mBoundary.h = backBoundary.h = h;
	this->status = NULL;
	this->baseZPanel = NULL;
	this->backgroundColor = _DEF_BACKGROUND_COLOR;
	this->mZGraphical = new ZGraphical();
}

ZPanel::~ZPanel()
{
	delete mZGraphical;
}

void ZPanel::onPaint(ZGraphical * mZGraphical)
{
	if (this->isDisplay) {
		/* ÏÔÊ¾Ãæ°å */
		mZGraphical->drawRect(&this->mBoundary,this->backgroundColor);
	}
}

void ZPanel::setDispaly(u8 isDisplay)
{
	this->isDisplay =  isDisplay;
	this->onPaint(this->mZGraphical);
}

void ZPanel::show()
{
	onPaint(this->mZGraphical);
}

void ZPanel::setBackgroundColor(COLOR backgroundColor)
{
	this->backgroundColor = backgroundColor;
	this->onPaint(this->mZGraphical);
}

void ZPanel::setLocation(s32 x, s32 y)
{
	this->backBoundary.left = this->mBoundary.left;
	this->backBoundary.top = this->mBoundary.top;
	this->mBoundary.left = x;
	this->mBoundary.top = y;
	if (this->baseZPanel != NULL) {
		this->baseZPanel->show();
	}
	else {
		this->show();
	}
}

void ZPanel::getLocation(Point & mPoint)
{
	mPoint.x = this->mBoundary.left;
	mPoint.y = this->mBoundary.top;
}

ZRectI * ZPanel::getBackBoundary()
{
	return &this->backBoundary;
}

ZGraphical * ZPanel::getGraphical()
{
	return this->mZGraphical;
}
void ZPanel::setEnable(u8 isEnable)
{
	this->isEnable = isEnable;
	this->show();
}
void ZPanel::postMsg(Msg * msg)
{
}

void ZPanel::msgDispose()
{
}

ZPanel * ZPanel::getBasePanel()
{
	return this->baseZPanel;
}

void ZPanel::setBasePanel(ZPanel * mZPanel)
{
	this->baseZPanel = mZPanel;
}

u8 ZPanel::getIsCustom(void)
{
	return u8(isCustom);
}
