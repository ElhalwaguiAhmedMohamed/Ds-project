#include "ActionSelect.h"
#include <iostream>
#include "ActionPlayWithColors.h"
#include "ActionPlayWithShapes.h"
#include "..\ApplicationManager.h"
#include <string>
#include <iostream>
int ActionSelect::selectedEllipses = 0;
int ActionSelect::selectedHexagons = 0;
int ActionSelect::selectedSquares = 0;

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
			int playType = pManager->getSelectedCasePlay();
			if (playType == 1)
			{
				pGUI->PrintMessage("selected");
				ActionPlayWithShapes* playWithShapes = new ActionPlayWithShapes(pManager);
				playWithShapes->ExecuteSelected(fig);
			}
			else if (playType == 2)
			{
				ActionPlayWithColors* playWithColors = new ActionPlayWithColors(pManager);
				playWithColors->Execute();
			}
			else if (playType == 3)
			{
			}
		}
	}

}


