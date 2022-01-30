#include "ActionChngFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"



ActionChngFillColor::ActionChngFillColor(ApplicationManager* pApp, int f) :Action(pApp)
{
	Flag = f;
}

//Execute the action
void ActionChngFillColor::Execute()
{
	GUI* pGui = pManager->GetGUI();

	switch (Flag)
	{
	case 1:
		UI.IsFilled = true;
		pGui->getColorIsFilled();
		UI.FillColor = RED;
		break;
	case 2:
		UI.IsFilled = true;
		pGui->getColorIsFilled();
		UI.FillColor = GREEN;
		break;
	case 3:
		UI.IsFilled = true;
		pGui->getColorIsFilled();
		UI.FillColor = BLUE;
		break;
	case 4:
		UI.IsFilled = true;
		pGui->getColorIsFilled();
		UI.FillColor = YELLOW;
		break;
	};


}
