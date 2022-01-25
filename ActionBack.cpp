#include "Actions/ActionBack.h"

#include "ApplicationManager.h"

#include "GUI/GUI.h"

SendBack::SendBack(ApplicationManager* pApp) :Action(pApp)
{

}

void SendBack::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int selectedIndex = pManager->getSelectedFigure();
	if (selectedIndex != -1) {
		pManager->SendToBack(selectedIndex);
		pGUI->ClearDrawArea();
	}
	else {
		pGUI->PrintMessage("Select a shape before you can perform this action");
	}
}
