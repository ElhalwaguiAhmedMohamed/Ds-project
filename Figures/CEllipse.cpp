#include "CEllipse.h"
CEllipse::CEllipse(): CFigure(){}
CEllipse::CEllipse(Point P1, int len, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	radius = len;
}

void CEllipse::Load(ifstream& inputFile)
{
}

void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	//pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	pGUI->DrawEllipse(center, radius, FigGfxInfo, Selected);


}