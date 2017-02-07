#include "stdafx.h"

#include <conio.h>
#include "ZWindows.h"

ZWindows::ZWindows(s32 x, s32 y, s32 w, s32 h, Font16 * text):ZPanel(x,y,w,h)
{
	this->text = text;
	this->mWindowsStyle.Color0 = 0xFFFFFF;
	this->mWindowsStyle.Color1 = 0x323232;
	this->mWindowsStyle.Color2 = 0x969696;
	this->mWindowsStyle.HeadColor0 = 0x786464;
	this->mWindowsStyle.HeadColor1 = 0xfac8c8;
	this->mWindowsStyle.TitleColor = 0xffffff;
	this->mWindowsStyle.TitleHeight = 22;

	this->firstPaint = FALSE;
	this->isCustom = FALSE;
	this->mWindowsEventDispose = NULL;

	this->closeButton = new ZButton(w - 22, -18, 16, 16, (u16*)L"X");
	//this->add(closeButton);
	this->isRunStatus = NONE;
}

ZWindows::~ZWindows()
{
	delete closeButton;
}

void ZWindows::postMsg(Msg * msg)
{
	this->mMsgList.push_front(msg);
}

void ZWindows::msgDispose()
{
	static Point clickTitleWinPoint;
	/* ��Ϣ�ı��� */
	list<Msg*>::iterator msgControl;
	list<ZPanel*>::iterator iterControl;

		/* ������Ϣ�б� */
	for (msgControl = mMsgList.begin(); msgControl != mMsgList.end(); msgControl++) {
		Msg *msg;
		msg = *msgControl;
		switch ((u32)msg->message) {
			case MOUSE_MSG_DOWN:

				/* ����˱����� */
				ZRectI pointRect;
				pointRect.left = msg->pt.x; pointRect.top = msg->pt.y;
				pointRect.w = 1; pointRect.h = 1;
				if (titleRect.IsIntersect(pointRect) && this->isRunStatus != MOVE) {
					clickTitleWinPoint.x = msg->pt.x;
					clickTitleWinPoint.y = msg->pt.y;
					/* ��������� */
					this->isRunStatus = MOVE;
					//_cprintf("click down..\r\n");
				}

				if (this->mWindowsEventDispose != NULL) {
					/* �¼������� */
					this->mWindowsEventDispose->windowsEventDispose(msg);
				}
				break;
			case MOUSE_MSG_RELEASE:

				if (this->isRunStatus == MOVE) {
					this->isRunStatus = NONE;
					//_cprintf("click release..\r\n");
				}

				if (this->mWindowsEventDispose != NULL) {
					/* �¼������� */
					this->mWindowsEventDispose->windowsEventDispose(msg);
				}
				break;
			case MOUSE_MSG_MOVE:

				if (this->isRunStatus == MOVE) {
					//_cprintf("click move..\r\n");
					Point mPoint;
					this->getLocation(mPoint);
					/* �ƶ���� */
					this->setLocation(
						mPoint.x + (msg->pt.x - clickTitleWinPoint.x),
						mPoint.y + (msg->pt.y - clickTitleWinPoint.y));
					clickTitleWinPoint.x = msg->pt.x;
					clickTitleWinPoint.y = msg->pt.y;
				}
				break;
		}
		for (iterControl = mZPanelList.begin(); iterControl != mZPanelList.end(); iterControl++) {
			ZPanel *mZPanel;
			mZPanel = *iterControl;
			/* ���ؼ�������Ϣ */
			mZPanel->postMsg(msg);
			mZPanel->msgDispose();
		}
	}
	this->mMsgList.clear();
}

void ZWindows::setWindowEventCallBack(WindowsEventInterface * mWindowsEventDispose)
{
	this->mWindowsEventDispose = mWindowsEventDispose;
}

void ZWindows::setFont(ZFontInterface * mZFontInterface)
{
	this->mZGraphical->setFont(mZFontInterface);
}

void ZWindows::add(ZPanel *mZPanel)
{
	int originalX;
	int originalY;
	int controlX;
	int controlY;
	/* �ؼ����õ���ʼλ�� */
	if (this->isCustom) {
		controlX = 0;
		controlY = 0;
	}
	else {
		controlX = 2;
		controlY = 2 + this->mWindowsStyle.TitleHeight;
	}
	originalX = mZPanel->getBoundary()->left;
	originalY = mZPanel->getBoundary()->top;
	mZPanel->setLeft(this->getBoundary()->left + mZPanel->getBoundary()->left+ controlX);
	mZPanel->setTop(this->getBoundary()->top + mZPanel->getBoundary()->top+ controlY);
	/* ȡ�ô��ڵ����� */
	mZPanel->setFont(this->mZGraphical->getFont());
	/* ���ø����� */
	mZPanel->setBasePanel(this);
	this->mZPanelList.push_front(mZPanel);
}

void ZWindows::setCustom(u8 isCustom)
{
	this->isCustom = isCustom;
	//this->show();
}

Font16 * ZWindows::getText(void)
{
	return this->text;
}

void ZWindows::showControl(ZPanel * mZPanel)
{
	int originalX;
	int originalY;
	int controlX;
	int controlY;
	/* �ؼ����õ���ʼλ�� */
	/* �ؼ����õ���ʼλ�� */
	if (this->isCustom) {
		controlX = 0;
		controlY = 0;
	}
	else {
		controlX = 2;
		controlY = 2 + this->mWindowsStyle.TitleHeight;
	}
	originalX = mZPanel->getBoundary()->left;
	originalY = mZPanel->getBoundary()->top;

	/* �������ÿؼ���λ�� */
	mZPanel->setLeft(this->getBoundary()->left - this->getBackBoundary()->left
	+ originalX
	);
	mZPanel->setTop(this->getBoundary()->top - this->getBackBoundary()->top
	+ originalY 
	);
	mZPanel->show();
}

void ZWindows::loadWindow()
{
	/*ZRectI *mRect = this->getBoundary();

	this->closeButton = new ZButton(mRect->w-22,-18, 16, 16, (u16*)L"X");
	this->add(closeButton);*/
	this->add(closeButton);
	this->closeButton->setFont(this->mZGraphical->getFont());
}

void ZWindows::onPaint(ZGraphical * mZGraphical)
{
	s32 x, y, w, h;
	x = this->mBoundary.left;
	y = this->mBoundary.top;
	w = this->mBoundary.w;
	h = this->mBoundary.h;
	s32 x_temp = mZGraphical->getDrawBound()->left;
	s32 y_temp = mZGraphical->getDrawBound()->top;
	s32 w_temp = mZGraphical->getDrawBound()->w;
	s32 h_temp = mZGraphical->getDrawBound()->h;

	ZRectI  resultRectI;
	
	if (!firstPaint) {
		firstPaint = TRUE;
		loadWindow();
	}
	/* �����ͼ�ı߽� */
	this->getBoundary()->getIntersectArea(*mZGraphical->getDrawBound(), resultRectI);
	/* ���û�ͼ�ı߽� */
	mZGraphical->setDrawBound(resultRectI.left, resultRectI.top, resultRectI.w, resultRectI.h);
	if (this->isDisplay) {
		/* ���� */
		mZGraphical->drawRect(x, y, w, h, this->backgroundColor);
		if (!this->isCustom) {
			/* ���Ƶײ��Ĵ��ڱ߿� */
			mZGraphical->drawLine(x + 1, y + 1, x + w - 1, y, this->mWindowsStyle.Color0);
			mZGraphical->drawLine(x + 1, y + 1, x, y + h - 1, this->mWindowsStyle.Color0);
			mZGraphical->drawLine(x + w - 1, y, x + w - 1, y + h - 1, this->mWindowsStyle.Color1);
			mZGraphical->drawLine(x, y + h - 1, x + w - 1, y + h - 1, this->mWindowsStyle.Color1);
			mZGraphical->drawLine(x + w - 2, y + 1, x + w - 1, y + h - 1, this->mWindowsStyle.Color2);
			mZGraphical->drawLine(x + 1, y + h - 2, x + w - 1, y + h - 1, this->mWindowsStyle.Color2);
			
			titleRect.left = x + 3;
			titleRect.top = y + 3;
			titleRect.w = w - 6;
			titleRect.h = this->mWindowsStyle.TitleHeight;
			mZGraphical->drawGradientRect(titleRect.left, titleRect.top,
				titleRect.w,
				titleRect.h,
				this->mWindowsStyle.HeadColor0,
				this->mWindowsStyle.HeadColor1,
				SHADE_LEFTRIGHT);


			/* �������ݣ������Զ�����*/
			mZGraphical->drawStringEx(x + 4, y + 4, w - 7, this->mWindowsStyle.TitleHeight,
				this->text, this->mWindowsStyle.TitleColor);
			
			showControl(closeButton);

		}
		/* �ڲ��ؼ��ı��� */
		list<ZPanel*>::iterator panelControl;

		for (panelControl = mZPanelList.begin(); panelControl != mZPanelList.end(); panelControl++) {
			ZPanel *mPanel = *panelControl;
			/* ���ÿؼ��Ļ�ͼ�߿� */
			mPanel->getGraphical()->setDrawBound(resultRectI.left, resultRectI.top, resultRectI.w, resultRectI.h);
			if (mPanel != (ZPanel*)closeButton) {
				/* ������ʾ */
				showControl(mPanel);
			}else {
				
			}

		}
		/* λ�ø�λ���� */
		this->getBackBoundary()->left = this->getBoundary()->left;
		this->getBackBoundary()->top = this->getBoundary()->top;
	}
	mZGraphical->setDrawBound(x_temp, y_temp, w_temp, h_temp);
}
