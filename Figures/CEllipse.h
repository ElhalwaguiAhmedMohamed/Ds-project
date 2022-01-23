#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point center;
	int radius;
public:
	CEllipse();
	CEllipse(Point, int, GfxInfo FigureGfxInfo);
	virtual void Load(ifstream& inputfile);
	virtual void DrawMe(GUI* pOut) const;
};

#endif

