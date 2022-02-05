#include "ActionSelect.h"
#include <iostream>
#include "ActionPlayWithColors.h"
#include "ActionPlayWithShapes.h"
#include "..\ApplicationManager.h"
#include <string>
#include <iostream>
ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp) ///constructor chaining
{

}

void ActionSelect::Execute()
{
	int* selectedFigCount = pManager->getSelectedFigCount();
	if (UI.InterfaceMode == MODE_DRAW || UI.InterfaceMode == MODE_COLOR || UI.InterfaceMode == MODE_FILL_COLOR) {
		int cx;
		int cy;

		GUI* pGUI = pManager->GetGUI();

		pGUI->GetPointClicked(cx, cy);

		CFigure* fig = pManager->GetFigure(cx, cy);




		if (fig != NULL) {

			if (fig->IsSelected()) {
				fig->ChngDrawClr(fig->ChngSelectClr());
				fig->SetSelected(false);
				*selectedFigCount = *selectedFigCount - 1;
				pGUI->ClearStatusBar();
			}
			else {
				fig->ChngSelectClr(fig->GetCurrentDrawClr());
				fig->ChngDrawClr(CADETBLUE);
				fig->SetSelected(true);
				*selectedFigCount = *selectedFigCount + 1;
				pGUI->PrintMessage(fig->ShowFigureDetails());


			}
		}
		else {

			CFigure* selectedFiguer = pManager->GetSelectedFigure();
			if (selectedFiguer != NULL) {
				selectedFiguer->ChngDrawClr(selectedFiguer->ChngSelectClr());
				selectedFiguer->SetSelected(false);
				pGUI->ClearStatusBar();
			}
		}
	}
	else if (UI.InterfaceMode == MODE_PLAY) {
		///selecting in playmode to delete the shape after selection
		int cx;
		int cy;

		GUI* pGUI = pManager->GetGUI();

		pGUI->GetPointClicked(cx, cy);

		CFigure* fig = pManager->GetFigure(cx, cy);

		if (fig != NULL)
		{
			fig->SetSelected(true);
			if (pManager->getSelectedCasePlay() == 1)
			{
				ActionPlayWithShapes* newAct = new ActionPlayWithShapes(pManager);
				newAct->Continue(fig);
			}
			else if (pManager->getSelectedCasePlay() == 2)
			{
				ActionPlayWithColors*newAct = new ActionPlayWithColors(pManager);
				newAct->ExecuteSelected(fig);
			}
			else if (pManager->getSelectedCasePlay() == 3)
			{
				// Implement your Action here and put this statment inside it
				//pManager->setSelectedCasePlay(3);
				// Load a file at the beginnig of the function (You can see playwithcolors action to see what i mean)
			}

		}
	}

}