#include "CSquare.h"
#include <fstream>
#include<iostream>

CSquare::CSquare() {}
CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}
 void CSquare:: Resize(float resize){
	 if (FigGfxInfo.Resize_Factor == .5) FigGfxInfo.Resize_Factor = -1;
	 else if (FigGfxInfo.Resize_Factor == .25) FigGfxInfo.Resize_Factor = -(4.0 / 3);

	 Point O;
	 O.x = (Corner1.x + Corner2.x) / 2;
	 O.y = (Corner1.y + Corner2.y) / 2;

	 if (Corner1.x <= O.x)
		 Corner1.x -= (O.x - Corner1.x) * FigGfxInfo.Resize_Factor / 2;
	 else
		 Corner1.x += (Corner1.x - O.x) * FigGfxInfo.Resize_Factor / 2;

	 if (Corner2.x <= O.x)
		 Corner2.x -= (O.x - Corner2.x) * FigGfxInfo.Resize_Factor / 2;
	 else
		 Corner2.x += (Corner2.x - O.x) * FigGfxInfo.Resize_Factor / 2;

	 if (Corner1.y <= O.y)
		 Corner1.y -= (O.y - Corner1.y) * FigGfxInfo.Resize_Factor / 2;
	 else
		 Corner1.y += (Corner1.y - O.y) * FigGfxInfo.Resize_Factor / 2;

	 if (Corner2.y <= O.y)
		 Corner2.y -= (O.y - Corner2.y) * FigGfxInfo.Resize_Factor / 2;
	 else
		 Corner2.y += (Corner2.y - O.y) * FigGfxInfo.Resize_Factor / 2;
		 
}
void CSquare::Load(ifstream &inputFile) {
	string borderColor , fillColor;
	int borderWidth; //to read the width of each figure's border
	inputFile>>ID >> TopLeftCorner.x >> TopLeftCorner.y>>length ;

	

	inputFile>>borderColor;
	this->FigGfxInfo.DrawClr = StringToColor(borderColor);
	
	inputFile >> fillColor;
	//cout << borderColor<< endl << fillColor << endl;
	
	if (fillColor == "NO-FILL") {
		//cout << fillColor << endl;
		this->FigGfxInfo.isFilled = false;
	}
	else
	{
		this->FigGfxInfo.isFilled = true;
		this->FigGfxInfo.FillClr = StringToColor(fillColor);
	}
	/*inputFile >> borderWidth;
	this->FigGfxInfo.BorderWdth = borderWidth;*/
	
	
	//inputFile >> this->FigGfxInfo.Resize_Factor;
	Selected = true;
	this->setStored();
}

