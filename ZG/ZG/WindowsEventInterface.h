#pragma once

#include "ZMsgDispose.h"
class WindowsEventInterface {
public:
	virtual void windowsEventDispose(Msg *msg) = 0;
};