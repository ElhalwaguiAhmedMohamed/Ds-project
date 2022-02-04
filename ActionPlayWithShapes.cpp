#include "Actions/ActionPlayWithShapes.h"
#include "Actions/ActionLoad.h"
#include "ApplicationManager.h"
#include "GUI/GUI.h"
#include <math.h>
#include <iostream>

ActionPlayWithShapes::ActionPlayWithShapes(ApplicationManager* pMan) :Action(pMan) {
	
}


void ActionPlayWithShapes::Execute() {
	Action* newAct = new ActionLoad(pManager, 1);
	newAct->Execute();
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
