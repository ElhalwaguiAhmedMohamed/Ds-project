#ifndef ACTION_SEND_BACK_H
#define ACTION_SEND_BACK_H

#include "Action.h"
#pragma once
class ActionSendBack : public Action
{
public:
	ActionSendBack(ApplicationManager* pApp);
	void Execute();

};

#endif
