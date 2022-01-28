#include "CEllipse.h"
#include <fstream>

CEllipse::CEllipse(): CFigure(){}
CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeft = P1;
	LowerRight = P2;
	Center.x = (P1.x + P2.x) / 2;
	Center.y = (P1.y + P2.y) / 2;
	a = abs(TopLeft.x - Center.x);
	b = abs(TopLeft.y - Center.y);
}

bool CEllipse::Get(int x, int y) const
{
	// (x - h) ^ 2 / a ^ 2 + (y - k) ^ 2 / b ^ 2 <= 1
	// center(h,k)
	// a is radius x-axis
	// b is radius y-axis
	if (pow(x - Center.x, 2) / pow(a, 2) + pow(y - Center.y, 2) / pow(b, 2) <= 1)
	{
		return true;
	}
	return false;
}

string CEllipse::ShowFigureDetails() const {
	return
		"ID=" + to_string(ID) + " "
		"| start point(" + to_string(TopLeft.x) + "," + to_string(TopLeft.y) + ") "
		"| end point(" + to_string(LowerRight.x) + "," + to_string(LowerRight.y) + ") "
		"| center point(" + to_string(Center.x) + "," + to_string(Center.y) + ") "
		"| radius x-axis=" + to_string(a) +" "
		"| radius y-axis=" + to_string(b) +" "
		"| area=" + to_string(M_PI*a*b);
}

void CEllipse::Load(ifstream& inputFile)
{
	string borderColor, fillColor;
	//int borderWidth; //to read the width of each figure's border
	inputFile >> ID >> TopLeft.x>> TopLeft.y >> LowerRight.x >> LowerRight.y;



	inputFile >> borderColor;
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

void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	//pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	pGUI->DrawEllipse(TopLeft, LowerRight, FigGfxInfo, Selected);


}

void CEllipse::Save(ofstream& outputFile)
{
	if (outputFile.is_open())
	{
		/*cout << "here" << endl;*/
		outputFile << "ELLIPSE"
			<< " " << ID
			<< " " << TopLeft.x
			<< " " << TopLeft.y
			<< " " << LowerRight.x
			<< " " << LowerRight.y
			<< " " << ColorToString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			outputFile << " " << "NO-FILL";
		else
			outputFile << " " << ColorToString(this->FigGfxInfo.FillClr);
		outputFile << "\n";
	}


}