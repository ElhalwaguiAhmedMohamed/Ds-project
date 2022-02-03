#ifndef ACTION_SELECT_H
#define ACTION_SELECT_H

#include "Action.h"

//Add Select Action class
class ActionSelect :  public Action
{
private:
	static int selectedSquares;
	static int selectedHexagons;
	static int selectedEllipses;
public:
	
	ActionSelect(ApplicationManager* pApp);


	//Add Select to the ApplicationManager
	virtual void Execute();
	
};
#endif
