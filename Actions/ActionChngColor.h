#ifndef ACTION_CHNG_COLOR_H
#define ACTION_CHNG_COLOR_H

#include "Action.h"

//Add Ellipse Action class
class ActionChngColor : public Action
{
	int Flag;
public:
	ActionChngColor(ApplicationManager* pApp);
	ActionChngColor(ApplicationManager* pApp, int);

	//Add Ellipse to the ApplicationManager
	virtual void Execute();

};

#endif

