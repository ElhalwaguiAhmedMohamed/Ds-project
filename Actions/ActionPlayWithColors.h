#pragma once
#include "Action.h"
class ActionPlayWithColors: public Action
{
public:
	ActionPlayWithColors(ApplicationManager* pApp);
	void Execute();
};

