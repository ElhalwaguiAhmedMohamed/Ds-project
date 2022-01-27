#pragma once

#include "Action.h"
#include "../ApplicationManager.h"

class ActionResize:public Action
{
	CFigure* Selected;
public :
	ActionResize(ApplicationManager* pApp, CFigure*);

	virtual void ReadActionParameters();

	
	virtual void Execute();
};

