#include "ActionPlayWithColors.h"
#include "ActionDelete.h"
#include "ActionLoad.h"
#include "../ApplicationManager.h"
#include <iostream>
int ActionPlayWithColors::randomColorsGenerator = 0;
int ActionPlayWithColors::wrong = 0;
int ActionPlayWithColors::right = 0;
ActionPlayWithColors::ActionPlayWithColors(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionPlayWithColors::Execute()
{
	// reset Counters
	ActionPlayWithColors::wrong = 0;
	ActionPlayWithColors::right = 0;
	// Load File saved from Draw Mode
	Action* newAct = new ActionLoad(pManager, 1);
	newAct->Execute();
	pManager->setSelectedCasePlay(2);
	// getting figures colors count
	int* figuresColors = new int[5]{ 0 };
	pManager->getFiguresColors(figuresColors);

	GUI* pGui = pManager->GetGUI();
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (figuresColors[i] != 0)
			count++;
		if (count > 0) break;
	}
	if (count == 0) // if all elements is zero then there are no figures
		pGui->PrintMessage("Draw shapes in draw mode first or load a graph :)");
	else {
		
		bool regenerate = true;  //randomizing what to choose
		do {
			ActionPlayWithColors::randomColorsGenerator = rand() % 5;
			if (ActionPlayWithColors::randomColorsGenerator == 0 && figuresColors[0] != 0) {
				regenerate = false;
			}
			else if (ActionPlayWithColors::randomColorsGenerator == 1 && figuresColors[1] != 0) {
				regenerate = false;
			}
			else if (ActionPlayWithColors::randomColorsGenerator == 2 && figuresColors[2] != 0) {
				regenerate = false;
			}
			else if (ActionPlayWithColors::randomColorsGenerator == 3 && figuresColors[3] != 0) {
				regenerate = false;
			}
			else if (ActionPlayWithColors::randomColorsGenerator == 4 && figuresColors[4] != 0) {
				regenerate = false;
			}
		} while (regenerate);
		if (ActionPlayWithColors::randomColorsGenerator == 0) {
			pGui->PrintMessage("Pick Red Shapes");

		}
		else if (ActionPlayWithColors::randomColorsGenerator == 1) {
			pGui->PrintMessage("Pick Green Shapes");
		}
		else if (ActionPlayWithColors::randomColorsGenerator == 2) {
			pGui->PrintMessage("Pick Blue Shapes");
		}
		else if (ActionPlayWithColors::randomColorsGenerator == 3)
		{
			pGui->PrintMessage("Pick Yellow Shapes");
		}
		else if(ActionPlayWithColors::randomColorsGenerator == 4)
		{
			pGui->PrintMessage("Pick Shapes which are not filled");
		}

	}
}

void ActionPlayWithColors::ExecuteSelected(CFigure* fig)
{
	GUI* pGui = pManager->GetGUI();

	// Get Figure fill color
	color fill = fig->GetCurrentFillClr();
	
	//Convert Color name to string
	string CurrentColor = "";
	if ((fill.ucBlue == BLUE.ucBlue) && (fill.ucGreen == BLUE.ucGreen) && (fill.ucRed == BLUE.ucRed))
		CurrentColor = "BLUE";
	else if ((fill.ucBlue == RED.ucBlue) && (fill.ucGreen == RED.ucGreen) && (fill.ucRed == RED.ucRed))
		CurrentColor = "RED";
	else if ((fill.ucBlue == YELLOW.ucBlue) && (fill.ucGreen == YELLOW.ucGreen) && (fill.ucRed == YELLOW.ucRed))
		CurrentColor =  "YELLOW";
	else if ((fill.ucBlue == GREEN.ucBlue) && (fill.ucGreen == GREEN.ucGreen) && (fill.ucRed == GREEN.ucRed))
		CurrentColor = "GREEN";
	else
		CurrentColor = "NO_FILL";
	
	//Delete selected figure
	Action* deleteAct = new ActionDelete(pManager);
	deleteAct->Execute();

	// 
	cout << randomColorsGenerator << endl;
	int* figuresColors = new int[5]{ 0 };
	
	pManager->getFiguresColors(figuresColors);
	for (int i = 0; i < 5; i++)
		cout << figuresColors[i] << " ";
	cout << CurrentColor << endl;
	if (CurrentColor == "RED")
	{
		//figuresColors[0]--;
		if (ActionPlayWithColors::randomColorsGenerator == 0)
			ActionPlayWithColors::right++;
		else
			ActionPlayWithColors::wrong++;
	}
	else if (CurrentColor == "GREEN")
	{
		//figuresColors[1]--;
		if (ActionPlayWithColors::randomColorsGenerator == 1)
			ActionPlayWithColors::right++;
		else
			ActionPlayWithColors::wrong++;
	}
	else if (CurrentColor == "BLUE")
	{
		/*figuresColors[2]--;*/
		if (ActionPlayWithColors::randomColorsGenerator == 2)
			ActionPlayWithColors::right++;
		else
			ActionPlayWithColors::wrong++;
	}
	else if (CurrentColor == "YELLOW")
	{
		/*figuresColors[3]--;*/
		if (ActionPlayWithColors::randomColorsGenerator == 3)
			ActionPlayWithColors::right++;
		else
			ActionPlayWithColors::wrong++;
	}
	else
	{
		/*figuresColors[4]--;*/
		if (ActionPlayWithColors::randomColorsGenerator == 4)
			ActionPlayWithColors::right++;
		else
			ActionPlayWithColors::wrong++;
	}
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (figuresColors[i] != 0)
			count++;
		if (count > 0) break;
	}
	if (figuresColors[ActionPlayWithColors::randomColorsGenerator - 1] == 0 || count == 0)
	{
		string message = "You finished. Your grade is " + to_string(ActionPlayWithColors::right) + "/" + to_string((ActionPlayWithColors::wrong + ActionPlayWithColors::right));
		pGui->ClearStatusBar();
		pGui->PrintMessage(message);
	}
	else
	{
		string message = "You picked " + to_string(ActionPlayWithColors::wrong) + " Wrong Shapes and " + to_string(ActionPlayWithColors::right) + " right shapes";
		pGui->ClearStatusBar();
		pGui->PrintMessage(message);
	}
		



}
