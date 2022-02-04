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
	
	color allColors[4] = { RED ,GREEN ,BLUE ,YELLOW };
	setSelectedFillColor(allColors[Flag - 1]);
	/*switch (Flag)
	{
	case 1:
		if (*selectedFigCount == 0)
		{
			UI.IsFilled = true;
			pGui->getColorIsFilled();
			UI.FillColor = allColors[0];
		}else {
			pManager->setSelectedFillColor(allColors[0]);
		}
		
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
	};*/


}
void ActionChngFillColor::setSelectedFillColor(color figFillColor)
{
	GUI* pGUI = pManager->GetGUI();
	int* Figs = pManager->getFigCount();
	CFigure** FigsList = pManager->getFigList();
	int* selectedFigCount = pManager->getSelectedFigCount();
	if (*selectedFigCount == 0)
	{
		UI.IsFilled = true;
		pGUI->getColorIsFilled();
		UI.FillColor = figFillColor;
	}
	else {
		for (int i = 0; i < *Figs; i++) {
			if (FigsList[i]->IsSelected()) {
				FigsList[i]->ChngFillClr(figFillColor);
			}
		}
		pGUI->ClearDrawArea();
		pManager->UpdateInterface();
	}


}
