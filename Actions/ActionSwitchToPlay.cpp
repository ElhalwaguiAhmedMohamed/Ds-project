#include "ActionSwitchToPlay.h"
#include "ActionSave.h"
#include "ActionLoad.h"
#include "..\GUI\GUI.h"
#include "../ApplicationManager.h"

ActionSwitchToPlay::ActionSwitchToPlay(ApplicationManager* pMan):Action(pMan)
{
		
}

void ActionSwitchToPlay::Execute() {

	GUI* pGUI = pManager->GetGUI();
	UI.InterfaceMode = MODE_PLAY;
	pGUI->ClearToolBar();
	pGUI->CreatePlayToolBar();
	pGUI->PrintMessage("Welcome to play mode :)");
	
}