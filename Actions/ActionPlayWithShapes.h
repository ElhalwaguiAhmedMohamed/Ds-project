#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
class ActionPlayWithShapes : public Action
{
private:
	int correct = 0;
	int wrong = 0;
public:
	ActionPlayWithShapes(ApplicationManager* pMan);
	virtual void Execute();
	virtual void ExecuteSelected(CFigure* fig);
	
};

