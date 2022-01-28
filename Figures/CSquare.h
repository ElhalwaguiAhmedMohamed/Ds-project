#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	Point Corner1;
	Point Corner2;
	int length;
public:
	CSquare();
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	virtual void Load(ifstream& inputfile);
	virtual void DrawMe(GUI* pOut) const;
	virtual void Resize(float);
};

#endif