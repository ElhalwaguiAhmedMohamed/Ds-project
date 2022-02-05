#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
class ActionPlayWithColors: public Action
{
protected:
	static int randomColorsGenerator;
	static int wrong;
	static int right;
public:
	ActionPlayWithColors(ApplicationManager* pApp);
	void Execute();
	void ExecuteSelected(CFigure*);
};

