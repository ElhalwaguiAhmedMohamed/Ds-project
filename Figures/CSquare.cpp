#include "CSquare.h"
#include <fstream>
#include<iostream>
#include<string.h>

int CSquare::squareCount = 0;

CSquare::CSquare():CFigure() {
	shapeType = 's';//to indicate it in loading while playing mode
}
CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	Center.x = (P1.x + (P1.x + length)) / 2;
	Center.y = (P1.y + (P1.y + length)) / 2;
	squareCount++;
	shapeType = 's';
}

void CSquare::Save(ofstream& outputFile)
{
	if (outputFile.is_open())
	{
		outputFile << "SQR"
			<< "\t" << ID
			<< "\t" << TopLeftCorner.x
			<< "\t" << TopLeftCorner.y
			<< "\t" << length
			<< "\t\t" << ColorToString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			outputFile << "\t" << "NO-FILL";
		else
			outputFile << "\t" << ColorToString(this->FigGfxInfo.FillClr);
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

string CSquare::ShowFigureDetails() const {
	return 
		"ID=" + to_string(ID)+ " "
		"| start point(" + to_string(TopLeftCorner.x) + "," + to_string(TopLeftCorner.y)+ ") "
		"| end point(" + to_string(TopLeftCorner.x + length) + "," + to_string(TopLeftCorner.y + length)+ ") "
		"| center point(" + to_string(Center.x) + "," + to_string(Center.y) + ") "
		"| length=" + to_string(length)+
		"| area=" + to_string(pow(length,2));	
}

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
}
 void CSquare::Resize(float size){
	this->length= this->length* size;
		 
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


int CSquare::getCount() {
	return squareCount;
}