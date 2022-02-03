#include "ActionPlayWithColors.h"
#include "../ApplicationManager.h"
#include <vector>
ActionPlayWithColors::ActionPlayWithColors(ApplicationManager* pApp) :Action(pApp)
{

}

void ActionPlayWithColors::Execute()
{
	// getting figures colors count
	int* figuresColors = new int[4]{ 0 };
	pManager->getFiguresColors(figuresColors);
	GUI* pGui = pManager->GetGUI();
	int countEmpty = 0;
	for (int i = 0; i < 4; i++)
	{
		if (figuresColors[i] == 0)
			countEmpty++;
	}
	if (countEmpty == 0) // if all elements is zero then there are no figures
		pGui->PrintMessage("Draw shapes in draw mode first or load a graph :)");
	else {
		int randomColorsGenerator;
		bool regenerate = true;  //randomizing what to choose
		do {
			randomColorsGenerator = rand() % 4 + 1;
			if (randomColorsGenerator == 1 && figuresColors[0] != 0) {
				regenerate = false;
			}
			else if (randomColorsGenerator == 2 && figuresColors[1] != 0) {
				regenerate = false;
			}
			else if (randomColorsGenerator == 3 && figuresColors[2] != 0) {
				regenerate = false;
			}
			else if (randomColorsGenerator == 4 && figuresColors[3] != 0) {
				regenerate = false;
			}
		} while (regenerate);
		if (randomColorsGenerator == 1) {
			pGui->PrintMessage("Choose Shapes with fill color \"RED\"");
			if()
		}
		else if (randomColorsGenerator == 2) {
			pGui->PrintMessage("Choose Shapes with fill color \"GREEN\"");
		}
		else if (randomColorsGenerator == 3) {
			pGui->PrintMessage("Choose Shapes with fill color \"BLUE\"");
		}
		else if (randomColorsGenerator == 4)
		{
			pGui->PrintMessage("Choose Shapes with fill color \"YELLOW\"");
		}
	}
}