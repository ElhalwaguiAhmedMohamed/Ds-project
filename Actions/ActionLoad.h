#pragma once
#include "Action.h"
class ActionLoad :	public Action
{
private:
	string FileName;
public:
	ActionLoad(ApplicationManager* pMan); // constructor
	virtual void ReadParameters();
	virtual void Execute();
	//string convertToString(color c); //convert from color type to string
	color convertToColor(string s);
};

