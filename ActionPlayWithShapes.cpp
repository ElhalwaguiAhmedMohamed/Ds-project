#include "Actions/ActionPlayWithShapes.h"
#include "Actions/ActionLoad.h"
#include "ApplicationManager.h"
#include "Actions/ActionSelect.h"
#include "Actions/ActionDelete.h"
#include "GUI/GUI.h"
#include <math.h>
#include <iostream>

ActionPlayWithShapes::ActionPlayWithShapes(ApplicationManager* pMan) :Action(pMan) {
}


void ActionPlayWithShapes::Execute() {
	Action* newAct = new ActionLoad(pManager, 1);
	newAct->Execute();
	pManager->setSelectedCasePlay(1);
	int squareCount = pManager->getSquareCount();
	int ellipseCount = pManager->getEllipseCount();
	int hexCount = pManager->getHexCount();
	GUI* pGui = pManager->GetGUI();
	int randomShapesGenerator = 0;
	if (squareCount == 0 && ellipseCount == 0 && hexCount == 0) {
		pGui->PrintMessage("Draw shapes in draw mode first or load a graph :)");
	}
	else {
		if (squareCount == 0 && ellipseCount == 0 && hexCount == 0) {
			pGui->PrintMessage("Draw shapes first to play");
		}
		else {
			bool regenerate = true;  //randomizing what to choose
			do {
				randomShapesGenerator = rand() % 3 + 1;
				if (randomShapesGenerator == 1 && squareCount != 0) {
					regenerate = false;
				}
				else if (randomShapesGenerator == 2 && ellipseCount != 0) {
					regenerate = false;
				}
				else if (randomShapesGenerator == 3 && hexCount != 0) {
					regenerate = false;
				}
			} while (regenerate);
			if (randomShapesGenerator == 1) {
				pGui->PrintMessage("Choose squares");
			}
			else if (randomShapesGenerator == 2) {
				pGui->PrintMessage("Choose ellipses");
			}
			else if (randomShapesGenerator == 3) {
				pGui->PrintMessage("Choose hexagons");
			}
		}
	}
	//cout << squareCount << endl << ellipseCount << endl << hexCount << endl;
	

	

}


void ActionPlayWithShapes::ExecuteSelected(CFigure* fig) {
	GUI* pGUI = pManager->GetGUI();
	if (fig != NULL)
	{

		if (fig->IsSelected())
		{
			fig->ChngDrawClr(fig->ChngSelectClr());
			fig->SetSelected(false);
			pGUI->ClearStatusBar();
		}
		else
		{
			fig->ChngSelectClr(fig->GetCurrentDrawClr());
			fig->ChngDrawClr(CADETBLUE);
			fig->SetSelected(true);
			
			//pGUI->PrintMessage(fig->ShowFigureDetails());
			if (fig->getShapeType() == 's') {
				ActionSelect::selectedSquares++;
			}
			else if (fig->getShapeType() == 'h') {
				ActionSelect::selectedHexagons++;
			}
			else {
				ActionSelect::selectedEllipses++;
			}
		}
	}
	else
	{

		CFigure* selectedFiguer = pManager->GetSelectedFigure();
		if (selectedFiguer != NULL) {
			selectedFiguer->ChngDrawClr(selectedFiguer->ChngSelectClr());
			selectedFiguer->SetSelected(false);
			pGUI->ClearStatusBar();
		}
	}
	Action* newAct = new ActionDelete(pManager);
	pManager->ExecuteAction(newAct);
	//showing the game score 
	cout << pManager->getSquareCount() << endl << ActionSelect::selectedSquares << endl;
	cout << pManager->getEllipseCount() << endl << ActionSelect::selectedEllipses << endl;
	cout << pManager->getHexCount() << endl << ActionSelect::selectedHexagons << endl;
	if (ActionSelect::selectedSquares == pManager->getSquareCount() && pManager->getSquareCount() != 0) {
		string message = "You choose " + to_string(ActionSelect::selectedSquares) + " Squares and " + to_string(ActionSelect::selectedEllipses) + " Ellipses and " + to_string(ActionSelect::selectedHexagons) + ", Wrong choices count is " + to_string(ActionSelect::selectedEllipses + ActionSelect::selectedHexagons) + " and number of Correct choices is " + to_string(ActionSelect::selectedSquares) + " :)";
		pGUI->PrintMessage(message);
	}
	else if (ActionSelect::selectedEllipses == pManager->getEllipseCount() && pManager->getEllipseCount() != 0) {
		string message = "You choose " + to_string(ActionSelect::selectedSquares) + " Squares and " + to_string(ActionSelect::selectedEllipses) + " Ellipses and " + to_string(ActionSelect::selectedHexagons) + ", Wrong choices count is " + to_string(ActionSelect::selectedSquares + ActionSelect::selectedHexagons) + " and number of Correct choices is " + to_string(ActionSelect::selectedEllipses) + " :)";
		pGUI->PrintMessage(message);
	}
	else if (ActionSelect::selectedHexagons == pManager->getHexCount() && pManager->getHexCount() != 0) {
		string message = "You choose " + to_string(ActionSelect::selectedSquares) + " Squares and " + to_string(ActionSelect::selectedEllipses) + " Ellipses and " + to_string(ActionSelect::selectedHexagons) + " Hexagons" + ", Wrong choices count is " + to_string(ActionSelect::selectedEllipses + ActionSelect::selectedSquares) + " and number of Correct choices is " + to_string(ActionSelect::selectedHexagons) + " :)";
		pGUI->PrintMessage(message);
	}
}

