#include "ActionDelete.h"
#include <iostream>
#include "..\ApplicationManager.h"




ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)//constructor chaining
{}
void  ActionDelete::ReadActionParameters()
{

}
//Execute the action
void ActionDelete::Execute()
{
	GUI* pGui = pManager->GetGUI();
	DeleteShape();

}
ActionDelete::~ActionDelete()
{
}
void ActionDelete::DeleteShape() {
	GUI* pGUI = pManager->GetGUI();
	int* Figs = pManager->getFigCount();
	CFigure** FigsList = pManager->getFigList();
	int figSelectFlag = 0;
	for (int i = 0; i < *Figs; i++) {
		if (FigsList[i]->IsSelected())
		{
			delete FigsList[i];
			*Figs = *Figs - 1;
			figSelectFlag = 1;
			for (int j = i; j < *Figs; j++) {
				FigsList[j] = FigsList[j + 1];
			}
			i--;
		}
	}
	if (figSelectFlag == 1) {
		if(UI.InterfaceMode == MODE_DRAW)
			pGUI->PrintMessage("Figure Deleted");
		pGUI->ClearDrawArea();
		pManager->UpdateInterface();
	}
	else {
		pGUI->PrintMessage("Please Select A Figure ...");
	}
}