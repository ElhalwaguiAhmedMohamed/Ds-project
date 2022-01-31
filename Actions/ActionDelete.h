#pragma once
#include "Action.h"




class ActionDelete :
	public Action
{
	//CFigure* deletedFigure;
public:

	ActionDelete(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void DeleteShape();
	~ActionDelete();

};
