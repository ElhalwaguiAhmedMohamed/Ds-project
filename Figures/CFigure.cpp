#include "CFigure.h"

CFigure::CFigure(){}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

color CFigure::StringToColor(string s) {
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
	return BLACK;
}

void CFigure::setStored()
{
	//getting data from the stored file
	storedFill = FigGfxInfo.FillClr;
	storedDraw = FigGfxInfo.DrawClr;
	IsFilled = FigGfxInfo.isFilled;
}

color CFigure::GetCurrentDrawClr() {
	return FigGfxInfo.DrawClr;
}

void CFigure::ChngSelectClr(color Dclr) {

	FigGfxInfo.PreviousClr = Dclr;
}
color CFigure::ChngSelectClr() {
	return FigGfxInfo.PreviousClr;
}
