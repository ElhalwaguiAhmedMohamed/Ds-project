#include "ActionChngColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
ActionChngColor::ActionChngColor(ApplicationManager* pApp, int f) :Action(pApp)
{
	Flag = f;
}

//Execute the action
void ActionChngColor::Execute()
{
	switch (Flag)
	{
	case 1:
		UI.DrawColor = RED;
		break;
	case 2:
		UI.DrawColor = GREEN;
		break;
	case 3:
		UI.DrawColor = BLUE;
		break;
	case 4:
		UI.DrawColor = YELLOW;
		break;
	};
}
