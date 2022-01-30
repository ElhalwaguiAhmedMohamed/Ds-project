#include "ActionAddHex.h"
#include "..\Figures\CHex.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddHex::ActionAddHex(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHex::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = pGUI->getColorIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Hex data from the user

	pGUI->PrintMessage("New Hex: Click at first point to determine first Point of Hex");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Hex: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();

	if (P1.y < 50 || P2.y < 50 || P1.y>650 || P2.y>650)
	{
		pGUI->PrintMessage("draw inside drawing area");
	}
	else
	{
		//Step 2 - prepare Hex Data
		//User has entered two points P1&P2
		//2.1- Identify the Top left corner of the Hex
		Point TopLeft;
		TopLeft.x = P1.x < P2.x ? P1.x : P2.x;
		TopLeft.y = P1.y < P2.y ? P1.y : P2.y;

		//2.2- Calcuate Hex side legnth
		int Llen = abs(TopLeft.x - P2.x);

		//2.3- Calculate Hex R lengh:
		int R = sqrt(pow(Llen, 2) - pow((0.5 * Llen), 2));


		//Step 3 - Create a Hex with the parameters read from the user
		CHex* H = new CHex(TopLeft, Llen, R, SqrGfxInfo);

		//Step 4 - Add the Square to the list of figures
		pManager->AddFigure(H);
	}
}
