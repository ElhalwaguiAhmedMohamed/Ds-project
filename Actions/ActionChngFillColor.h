#ifndef ACTION_CHNG_FILL_COLOR_H
#define ACTION_CHNG_FILL_COLOR_H

#include "Action.h"

//Add Ellipse Action class
class ActionChngFillColor : public Action
{
	int Flag;
public:
	//ActionChngFillColor(ApplicationManager* pApp);

	ActionChngFillColor(ApplicationManager* pApp, int);

	//Add Ellipse to the ApplicationManager
	virtual void Execute();


};

#endif

