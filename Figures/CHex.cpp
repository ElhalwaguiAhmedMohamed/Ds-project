#include "CHex.h"
#include <fstream>
CHex::CHex() : CFigure() {}
CHex::CHex(Point P1, int len, int rlen, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeft = P1;
	Llen = len;
	Rlen = rlen;
}

void CHex::Load(ifstream& inputFile) {
	string borderColor, fillColor;
	int borderWidth; //to read the width of each figure's border
	inputFile >> ID >> TopLeft.x >> TopLeft.y >> Llen >> Rlen;



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
void CHex::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawPolygon to draw a Hex on the screen	
	pGUI->DrawHex(TopLeft, Llen, Rlen, FigGfxInfo, Selected);
	
}
