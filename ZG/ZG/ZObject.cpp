#include "ZGD.h"

#include "stdafx.h"

#include "ZObject.h"

ZRectI * ZObject::getBoundary()
{
	return 	&mBoundary;;
}

void ZObject::setTop(s32 top)
{
	mBoundary.top = top;
}

void ZObject::setLeft(s32 left)
{
	mBoundary.left = left;
}

void ZObject::setW(s32 w)
{
	mBoundary.w = w;

}

void ZObject::setH(s32 h)
{
	mBoundary.h = h;
}

void ZObject::setBoundary(ZRectI & mBoundary)
{
	this->mBoundary.top = mBoundary.top;
	this->mBoundary.left = mBoundary.left;
	this->mBoundary.w = mBoundary.w;
	this->mBoundary.h = mBoundary.h;
}

ZObject::ZObject()
{
	this->mBoundary.top =0;
	this->mBoundary.left = 0;
	this->mBoundary.w = 0;
	this->mBoundary.h = 0;
}

ZObject::ZObject(ZRectI & mBoundary)
{
	this->mBoundary.top = mBoundary.top;
	this->mBoundary.left = mBoundary.left;
	this->mBoundary.w = mBoundary.w;
	this->mBoundary.h = mBoundary.h;
}

ZObject::ZObject(s32 top, s32 left, s32 w, s32 h)
{
	this->mBoundary.top = top;
	this->mBoundary.left = left;
	this->mBoundary.w = w;
	this->mBoundary.h = h;
}

ZObject::~ZObject()
{

}
