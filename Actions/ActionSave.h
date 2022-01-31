#pragma once
#include "Action.h"
#include<string>
#include<fstream>
class ActionSave : public Action
{
private:
	string filename;
public:
	ActionSave(ApplicationManager* pApp);
	virtual void Execute();
	void ReadParameters();
	string ColorToString(color c);
};

