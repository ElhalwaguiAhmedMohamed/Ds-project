#include "ActionAddEllipse.h"
#include "..\Figures\CEllipse.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddEllipse::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Ellipse data from the user

	pGUI->PrintMessage("New Ellipse: Click at first point to determine center");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Ellipse: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();

	if (P1.y < 50 || P2.y < 50 || P1.y>650 || P2.y>650)
	{
		pGUI->PrintMessage("draw inside drawing area");
	}
	else
	{
		//Step 2 - prepare square data
		//User has entered two points P1&P2
		//2.1- Identify the Top left corner of the square
		Point center;
		center.x = P1.x < P2.x ? P1.x : P2.x;
		center.y = P1.y < P2.y ? P1.y : P2.y;

		//2.2- Calcuate square side legnth
		//The square side length would be the longer distance between the two points coordinates
		int radius = max(abs(P1.x - P2.x), abs(P1.y - P2.y));


		//Step 3 - Create a Square with the parameters read from the user
		CEllipse* R = new CEllipse(center, radius, SqrGfxInfo);

		//Step 4 - Add the Square to the list of figures
		pManager->AddFigure(R);
	}
}
