#include "ActionSwitchToPlay.h"
#include "ActionSave.h"
#include <fstream>

ActionSwitchToPlay::ActionSwitchToPlay(ApplicationManager* pMan) :Action(pMan)
{
	
}

void ActionSwitchToPlay::ReadActionParameters()
{
	GUI *pGui = pManager->GetGUI();
	pGui->PrintMessage("Welcome to play mode");
}

void ActionSwitchToPlay::Execute() {
	GUI* pGui = pManager->GetGUI();
	ReadActionParameters();
}