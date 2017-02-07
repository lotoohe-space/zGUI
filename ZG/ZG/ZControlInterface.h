#pragma once
#ifndef _ZCONTORLINTERFACE_H__
#define _ZCONTORLINTERFACE_H__
#include "ZPanel.h"
#include "ZMsgDispose.h"

class ZControlInterface {
public:
	virtual void ControlEventHandle(ZPanel *mZPanel, Msg* msg) = 0;
};

#endif // !_ZCONTORLINTERFACE_H__
