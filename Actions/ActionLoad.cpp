#include "ActionLoad.h"
#include <iostream>
#include <fstream>
#include <string>
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\\Output.h"
#include "../Actions/ActionSave.h"
#include "../Figures//CSquare.h"
#include "..\Figures\CHex.h"
#include "../Figures/CEllipse.h"
#include <iostream>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
ActionLoad :: ActionLoad(ApplicationManager *pMan , int _force) :Action(pMan) //chain 
{
	force = _force;
}

//void ActionLoad::ReadParameters() 
//{
//	GUI* pGui = pManager->GetGUI();
//	pGui->PrintMessage("Please write the file you want to load :)");
//	FileName = pGui->GetSrting(); //get the written string from the user
//
//}


void ActionLoad::Execute()
{
	if (force == 1) {
		load();
	}
	else {
		GUI* pGui = pManager->GetGUI();
		pGui->PrintMessage("If you want to save you graph before loading write (Y) else write (N) ");
		string s = pGui->GetSrting();
		if (s == "Y" || s == "y") {
			Action* newAct = new ActionSave(pManager);
			pManager->ExecuteAction(newAct);
			load();
		}
		else {
			load();
		}
	}


}


void ActionLoad::load() {
	ifstream inputFile;
	bool flag = false;
	GUI* pGui = pManager->GetGUI();
	string shape, drawColor, fillColor, bgColor;
	int numberOfShapes;
	CFigure* figure = NULL;

	if (force == 0) {
		char filename[MAX_PATH];

		OPENFILENAME ofn;
		ZeroMemory(&filename, sizeof(filename));
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
		ofn.lpstrFilter = "Text Files\0*.txt\0Any File\0*.*\0";
		ofn.lpstrFile = filename;
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrTitle = "Select a File, yo!";
		ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
		if (GetOpenFileNameA(&ofn))
		{
			std::cout << "You chose the file \"" << filename << "\"\n";
		}
		inputFile.open(ofn.lpstrFile);
	}
	else {
		inputFile.open("saver.txt");

	}
	

	
	
	
	//ReadParameters(); // get the file to start reading lines from it

	 //open the saved file as text
	pGui->ClearDrawArea(); //clear the current gui from any shapes
	//check if the file opened successfully 
	if (inputFile.fail()) {
		pGui->PrintMessage("Wrong file name :(");
		return;
	}
	//if the file opened successfully
	inputFile >> drawColor >> fillColor >> bgColor;
	UI.DrawColor = convertToColor(drawColor);
	UI.BkGrndColor = convertToColor(bgColor); //drawing area background color
	UI.FillColor = convertToColor(fillColor);
	pGui->ClearDrawArea();
	pManager->DeleteList();//to delete the current list itemsl
	inputFile >> numberOfShapes;
	while (numberOfShapes) {
		inputFile >> shape;
		if (shape == "SQR") {
			figure = new CSquare;
		}
		else if (shape == "HEX") {
			figure = new CHex;
		}
		else if (shape == "ELLIPSE") {
			figure = new CEllipse;
		}

		figure->Load(inputFile);
		pManager->AddFigure(figure);
		numberOfShapes--;
	}

	pManager->UpdateInterface();
	//pGui->PrintMessage("Graph loaded successfully :)");
	pGui->ClearStatusBar();
	pGui->CreateStatusBar();
	pGui->PrintMessage("Graph loaded successfully :)");
}

color ActionLoad::convertToColor(string s) {
	if (s == "BLACK")
		return BLACK;
	if (s == "BLUE")
		return BLUE;
	if (s == "WHITE")
		return WHITE;
	if (s == "RED")
		return RED;
	if (s == "YELLOW")
		return YELLOW;
	if (s == "GREEN")
		return GREEN;
	if (s == "LIGHTGOLDENRODYELLOW")
		return LIGHTGOLDENRODYELLOW;
	if (s == "MAGENTA")
		return MAGENTA;
	if (s == "TURQUOISE")
		return TURQUOISE;
	if (s == "SKYBLUE")
		return SKYBLUE;
	if (s == "LIGHTSTEELBLUE")
		return LIGHTSTEELBLUE;
	if (s == "IVORY")
		return IVORY;
	return BLACK;
}
