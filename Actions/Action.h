#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include "../Figures/CFigure.h"
class ApplicationManager; //forward class declaration


//Base class for all possible actions
///abstract class 
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Execute action (code depends on action type)
	virtual void Execute() =0; ///pure virtual function
	//virtual void ExecuteSelected(CFigure* fig);
	//To undo this action (code depends on action type)
	//virtual void Undo()=0;

	//To redo this action (code depends on action type)
	//virtual void Redo()=0;

};

#endif