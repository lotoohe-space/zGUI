
#include "stdafx.h"
#include "ZRadioButton.h"

ZRadioButton::ZRadioButton(u32 x, u32 y, u32 w, u32 h, Font16 * text) :ZLable(x, y, w, h, text)
{
	this->mLableClssStyle.Color1 = 0xffffff;
	this->mLableClssStyle.Color2 = 0x323232;
	this->mLableClssStyle.Color3 = 0x969696;
}

u8 ZRadioButton::getIsSelect(void)
{
	return u8(isSelect);
}

void ZRadioButton::onPaint(ZGraphical * mZGraphical)
{
	s32 x, y, w, h;
	x = this->mBoundary.left;
	y = this->mBoundary.top;
	w = this->mBoundary.w;
	h = this->mBoundary.h;

	if (this->isDisplay) {
			if (!isSelect) {
				mZGraphical->drawCircle(x + 7, (h - 15) / 2 + y + 7, 7, 0xffffff);
				//mZGraphical->drawCircle(x + 7, (h - 15) / 2 + y + 7, 7, 0xffffff);
			}
			else {
				mZGraphical->drawCircle(x + 7, (h - 15) / 2 + y + 7, 7, 0xffffff);
				//mZGraphical->drawCircle(x + 7, (h - 15) / 2 + y + 7, 7, 0xffffff);
			}
			u32 fontH = this->mZGraphical->getFont()->getFontHeight();
			u32 fontsW = this->mZGraphical->getFont()->getFontsWidth(this->text);
			//»­×ÖÌå
			mZGraphical->drawStringEx(x + 20, y+5, w, y + (h - fontH) / 2,
				this->text, 0xffffff);
	}
}
