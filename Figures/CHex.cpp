#include "CHex.h"
CHex::CHex() : CFigure() {}
CHex::CHex(Point P1, int len, int rlen, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeft = P1;
	Llen = len;
	Rlen = rlen;
}

void CHex::Load(ifstream& inputFile) {}
void CHex::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawPolygon to draw a Hex on the screen	
	pGUI->DrawHex(TopLeft, Llen, Rlen, FigGfxInfo, Selected);
	
}
