#ifndef ACTION_OPEN_PALETTE_H
#define ACTION_OPEN_PALETTE_H

#include "Action.h"

//Open Palette Action class
class ActionOpenPalette : public Action
{
	int Mode;
public:
	ActionOpenPalette(ApplicationManager* pApp);
	ActionOpenPalette(ApplicationManager* pApp,int);

	//Ask ApplicationManager to execute this action
	virtual void Execute();

};

#endif

