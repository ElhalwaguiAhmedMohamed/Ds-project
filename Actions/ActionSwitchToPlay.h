#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
class ActionSwitchToPlay : public Action
{
public:
	ActionSwitchToPlay(ApplicationManager*);

	virtual void ReadActionParameters();
	virtual void Execute();
	~ActionSwitchToPlay();
};

