#include "ActionChngBkColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"



ActionChngBkColor::ActionChngBkColor(ApplicationManager* pApp, int f) :Action(pApp)
{
	Flag = f;
}

//Execute the action
void ActionChngBkColor::Execute()
{

	GUI* pGui = pManager->GetGUI();
	//pGui->ClearToolBar();
	//pGui->CreateColorToolBar();
	switch (Flag)
	{
	case 1:
		UI.BkGrndColor = RED;
		pGui->ClearDrawArea();
		pManager->UpdateInterface();
		pGui->CreateDrawToolBar();
		break;
	case 2:
		UI.BkGrndColor = GREEN;
		pGui->ClearDrawArea();
		pManager->UpdateInterface();
		pGui->CreateDrawToolBar();
		break;
	case 3:
		UI.BkGrndColor = BLUE;
		pGui->ClearDrawArea();
		pManager->UpdateInterface();
		pGui->CreateDrawToolBar();
		break;
	case 4:
		UI.BkGrndColor = YELLOW;
		pGui->ClearDrawArea();
		pManager->UpdateInterface();
		pGui->CreateDrawToolBar();
		break;
	};


}

