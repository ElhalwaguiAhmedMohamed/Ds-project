#ifndef ACTION_CHNG_BK_COLOR_H
#define ACTION_CHNG_BK_COLOR_H

#include "Action.h"

//Change background color action class
class ActionChngBkColor : public Action
{
	int Flag;
public:
	ActionChngBkColor(ApplicationManager* pApp);
	ActionChngBkColor(ApplicationManager* pApp, int);

	//Ask application manager to execute this action
	virtual void Execute();


};

#endif


