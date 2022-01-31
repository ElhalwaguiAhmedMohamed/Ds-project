#include<iostream>

#include "ActionSave.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CHex.h"
#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
ActionSave::ActionSave(ApplicationManager* pApp):Action(pApp)
{
}

void ActionSave::Execute()
{
	if(filename!="saver")
	{
		ReadParameters();
	}
	GUI* pGui = pManager->GetGUI();
	ofstream outputfile((filename + ".txt"));
	if (outputfile.is_open())
	{
		outputfile << ColorToString(UI.DrawColor)
			<< "\t" << ColorToString(UI.FillColor)
			<< "\t" << ColorToString(UI.BkGrndColor)
			<< "\n";
		pManager->SaveAll(outputfile);

		pGui->PrintMessage("Graph Saved successfully :)");

		outputfile.close();
	}
	/*if (outputfile.fail()) {
		pGui->PrintMessage("Wrong file name :(");
		return;
	}*/
	
	
}




void ActionSave::ReadParameters()
{
	GUI* Pgui = pManager->GetGUI();
	
	while (true)
	{
		Pgui->PrintMessage("Enter the file name you want to save :)");
		filename = Pgui->GetSrting();
		if (filename != "")
		{
			break;
		}
	}
		
}
string ActionSave::ColorToString(color c) {
	
	if ((c.ucBlue == BLACK.ucBlue) && (c.ucGreen == BLACK.ucGreen) && (c.ucRed == BLACK.ucRed ))
		return "BLACK";
	if ((c.ucBlue == BLUE.ucBlue) && (c.ucGreen == BLUE.ucGreen) && (c.ucRed == BLUE.ucRed))
		return "BLUE";
	if ((c.ucBlue == WHITE.ucBlue) && (c.ucGreen == WHITE.ucGreen) && (c.ucRed == WHITE.ucRed))
		return "WHITE";
	if ((c.ucBlue == RED.ucBlue) && (c.ucGreen == RED.ucGreen) && (c.ucRed == RED.ucRed))
		return "RED";
	if ((c.ucBlue == YELLOW.ucBlue) && (c.ucGreen == YELLOW.ucGreen) && (c.ucRed == YELLOW.ucRed))
		return "YELLOW";
	if ((c.ucBlue == GREEN.ucBlue) && (c.ucGreen == GREEN.ucGreen) && (c.ucRed == GREEN.ucRed))
		return "GREEN";
	if ((c.ucBlue == LIGHTGOLDENRODYELLOW.ucBlue) && (c.ucGreen == LIGHTGOLDENRODYELLOW.ucGreen) && (c.ucRed == LIGHTGOLDENRODYELLOW.ucRed))
		return "LIGHTGOLDENRODYELLOW";
	if ((c.ucBlue == MAGENTA.ucBlue) && (c.ucGreen == MAGENTA.ucGreen) && (c.ucRed == MAGENTA.ucRed))
		return "MAGENTA";
	if ((c.ucBlue == TURQUOISE.ucBlue) && (c.ucGreen == TURQUOISE.ucGreen) && (c.ucRed == TURQUOISE.ucRed))
		return "TURQUOISE";
	if ((c.ucBlue == SKYBLUE.ucBlue) && (c.ucGreen == SKYBLUE.ucGreen) && (c.ucRed == SKYBLUE.ucRed))
		return "SKYBLUE";
	if ((c.ucBlue == LIGHTSTEELBLUE.ucBlue) && (c.ucGreen == LIGHTSTEELBLUE.ucGreen) && (c.ucRed == LIGHTSTEELBLUE.ucRed))
		return "LIGHTSTEELBLUE";
	return "NO-FILL";
}
