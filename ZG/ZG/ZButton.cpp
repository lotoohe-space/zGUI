
#include "stdafx.h"
#include "ZButton.h"

ZButton::ZButton(u32 x, u32 y, u32 w, u32 h, Font16 * text):ZLable(x,y,w,h,text)
{
	this->mLableClssStyle.Color1 = 0xffffff;
	this->mLableClssStyle.Color2 = 0x323232;
	this->mLableClssStyle.Color3 = 0x969696;
}
#include <conio.h>
#include "ZWindows.h"
void ZButton::onPaint(ZGraphical * mZGraphical)
{
	s32 x, y, w, h;
	x = this->mBoundary.left;
	y = this->mBoundary.top;
	w = this->mBoundary.w;
	h = this->mBoundary.h;
	if (this->text[0] == 'X') {
		_cprintf("X..\r\n" );
	}
	if (this->isDisplay) {
		if (this->status == CONTROL_DOWN) {
			//绘制矩形button
			mZGraphical->drawLine(x, y, x + w - 1, y, C24TO16(50, 50, 50));
			mZGraphical->drawLine(x, y, x, y + h - 1, C24TO16(50, 50, 50));
			mZGraphical->drawLine(x + 1, y + 1, x + w - 2, y + 1, C24TO16(150, 150, 150));
			mZGraphical->drawLine(x + 1, y + 1, x + 1, y + h - 2, C24TO16(150, 150, 150));
			mZGraphical->drawLine(x + w - 1, y + 1, x + w - 1, y + h - 1, C24TO16(255, 255, 255));
			mZGraphical->drawLine(x + 1, y + h - 1, x + w - 1, y + h - 1, C24TO16(255, 255, 255));
			
			u32 fontH = this->mZGraphical->getFont()->getFontHeight();
			u32 fontsW = this->mZGraphical->getFont()->getFontsWidth(this->text);

			/* 画文字 */
			mZGraphical->drawStringEx(fontsW>(w) ? (x + 2) : ((x + 2) + ((w)-fontsW) / 2),
				(y)+((h)-fontH) / 2, w, h,
				this->text, this->mLableClssStyle.Color0);
		}
		else {
			/* 绘制矩形button */
			mZGraphical->drawRect(x, y, w, h, backgroundColor);
			mZGraphical->drawLine(x, y, x + w - 1, y, this->mLableClssStyle.Color1);
			mZGraphical->drawLine(x, y, x, y + h - 1, this->mLableClssStyle.Color1);
			mZGraphical->drawLine(x + w - 1, y, x + w - 1, y + h - 1, this->mLableClssStyle.Color2);
			mZGraphical->drawLine(x, y + h - 1, x + w - 1, y + h - 1, this->mLableClssStyle.Color2);
			mZGraphical->drawLine(x + w - 2, y + 1, x + w - 1, y + h - 1, this->mLableClssStyle.Color3);
			mZGraphical->drawLine(x + 1, y + h - 2, x + w - 1, y + h - 1, this->mLableClssStyle.Color3);

			u32 fontH = this->mZGraphical->getFont()->getFontHeight();
			u32 fontsW = this->mZGraphical->getFont()->getFontsWidth(this->text);
			/* 画文字 */
			mZGraphical->drawStringEx(fontsW>(w) ? (x + 2) : ((x + 2) + ((w)-fontsW) / 2),
				(y)+((h)-fontH) / 2, w, h,
				this->text, this->mLableClssStyle.Color0);
		}
	}
}
