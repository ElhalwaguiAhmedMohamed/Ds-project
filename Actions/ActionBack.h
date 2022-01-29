#ifndef SEND_BACK_H
#define SEND_BACK_H

#include "Actions/Action.h"
#include "ApplicationManager.h"
#pragma once
class SendBack : public Action
{
public:
	SendBack(ApplicationManager* pApp);
	void Execute();

};

#endif
