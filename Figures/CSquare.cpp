#include "CSquare.h"
#include <fstream>
#include<iostream>

CSquare::CSquare() {}
CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}

void CSquare::Save(ofstream& outputFile)
{
	if (outputFile.is_open())
	{
		/*cout << "here" << endl;*/
		outputFile << "SQR"
			<< " " << ID
			<< " " << TopLeftCorner.x
			<< " " << TopLeftCorner.y
			<< " " << length
			<< " " << ColorToString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			outputFile << " " << "NO-FILL";
		else
			outputFile << " " << ColorToString(this->FigGfxInfo.FillClr);
		outputFile << "\n";
	}
	

}
	
bool CSquare::Get(int x, int y) const
{
	if (x>=TopLeftCorner.x&&x<=TopLeftCorner.x+ length&&
		y>= TopLeftCorner.y&& TopLeftCorner.y+length)
		return true;
	return false;
}
void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}

void CSquare::Load(ifstream &inputFile) {
	string borderColor , fillColor;
	//int borderWidth; //to read the width of each figure's border
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
	Selected = false;
	this->setStored();
}

