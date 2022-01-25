#include "CEllipse.h"
CEllipse::CEllipse(): CFigure(){}
CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeft = P1;
	LowerRight = P2;
}

void CEllipse::Load(ifstream& inputFile)
{
}

void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	//pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	pGUI->DrawEllipse(TopLeft, LowerRight, FigGfxInfo, Selected);


}