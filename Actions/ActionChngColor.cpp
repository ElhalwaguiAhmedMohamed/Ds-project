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
	color allColors[4] = { RED ,GREEN ,BLUE ,YELLOW };
	setSelectedDrawColor(allColors[Flag - 1]);
	/*switch (Flag)
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
	};*/
}
void ActionChngColor::setSelectedDrawColor(color figFillColor)
{
	GUI* pGUI = pManager->GetGUI();
	int* Figs = pManager->getFigCount();
	CFigure** FigsList = pManager->getFigList();
	int* selectedFigCount = pManager->getSelectedFigCount();
	if (*selectedFigCount == 0)
	{
		UI.DrawColor = figFillColor;
	}else {
		for (int i = 0; i < *Figs; i++) {
			if (FigsList[i]->IsSelected()) {
				FigsList[i]->SetSelected(false);
				*selectedFigCount = *selectedFigCount - 1;
				FigsList[i]->ChngDrawClr(figFillColor);
			}
		}
		pGUI->ClearDrawArea();
		pManager->UpdateInterface();
	}
	

}
