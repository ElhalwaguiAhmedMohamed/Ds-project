#include "ActionSelect.h"
#include <iostream>
#include "ActionDelete.h"
#include "..\ApplicationManager.h"
#include <string>
int ActionSelect::selectedEllipses = 0;
int ActionSelect::selectedHexagons = 0;
int ActionSelect::selectedSquares = 0;
ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp) ///constructor chaining
{}

void ActionSelect::Execute()
{
	if (UI.InterfaceMode == MODE_DRAW) {
		int cx;
		int cy;

		GUI* pGUI = pManager->GetGUI();

		pGUI->GetPointClicked(cx, cy);

		CFigure* fig = pManager->GetFigure(cx, cy);
		int* selectedFigCount = pManager->getSelectedFigCount();
		

	
	if (fig != NULL) {

			if (fig->IsSelected()) {
				fig->ChngDrawClr(fig->ChngSelectClr());
				fig->SetSelected(false);
				*selectedFigCount = *selectedFigCount - 1;
				pGUI->ClearStatusBar();
			}
			else {
				fig->ChngSelectClr(fig->GetCurrentDrawClr());
				fig->ChngDrawClr(MAGENTA);
				fig->SetSelected(true);
				*selectedFigCount = *selectedFigCount - 1;
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
	else if(UI.InterfaceMode = MODE_PLAY) {
		int cx;
		int cy;

		GUI* pGUI = pManager->GetGUI();

		pGUI->GetPointClicked(cx, cy);

		CFigure* fig = pManager->GetFigure(cx, cy);

		if (fig != NULL) 
		{

			if (fig->IsSelected()) 
			{
				fig->ChngDrawClr(fig->ChngSelectClr());
				fig->SetSelected(false);
				*selectedFigCount = *selectedFigCount - 1;
				pGUI->ClearStatusBar();
			}
			else 
			{
				fig->ChngSelectClr(fig->GetCurrentDrawClr());
				fig->ChngDrawClr(MAGENTA);
				fig->SetSelected(true);
				*selectedFigCount = *selectedFigCount + 1;
				pGUI->PrintMessage(fig->ShowFigureDetails());
				if (fig->getShapeType() == 's') {
					selectedSquares++;  
				}
				else if (fig->getShapeType() == 'h') {
					selectedHexagons++;
				}
				else {
					selectedEllipses++;
				}
			}
		}
		else 
		{

			CFigure* selectedFiguer = pManager->GetSelectedFigure();
			if (selectedFiguer != NULL) {
				selectedFiguer->ChngDrawClr(selectedFiguer->ChngSelectClr());
				selectedFiguer->SetSelected(false);
				*selectedFigCount = *selectedFigCount - 1;
				pGUI->ClearStatusBar();
			}
		}
		Action* newAct = new ActionDelete(pManager);
		pManager->ExecuteAction(newAct);
		//showing the game score 
		if (selectedSquares == pManager->getSquareCount() && pManager->getSquareCount()!=0) {
			string message = "You choose " + to_string(selectedSquares) + " Squares and " + to_string(selectedEllipses) + " Ellipses and " + to_string(selectedHexagons) + ", Wrong choices count is "+ to_string(selectedEllipses+selectedHexagons)+" and number of Correct choices is "+to_string(selectedSquares)+" :)";
			pGUI->PrintMessage(message);
		}
		else if (selectedEllipses == pManager->getEllipseCount() && pManager->getEllipseCount() != 0) {
			string message = "You choose " + to_string(selectedSquares) + " Squares and " + to_string(selectedEllipses) + " Ellipses and " + to_string(selectedHexagons) + ", Wrong choices count is " + to_string(selectedSquares + selectedHexagons) + " and number of Correct choices is " + to_string(selectedEllipses) + " :)";
			pGUI->PrintMessage(message);
		}
		else if (selectedHexagons == pManager->getHexCount() && pManager->getHexCount() != 0) {
			string message = "You choose " + to_string(selectedSquares) + " Squares and " + to_string(selectedEllipses) + " Ellipses and " + to_string(selectedHexagons) + " Hexagons"+ ", Wrong choices count is " + to_string(selectedEllipses + selectedSquares) + " and number of Correct choices is " + to_string(selectedHexagons) + " :)";
			pGUI->PrintMessage(message);
		}
	}
	
}
