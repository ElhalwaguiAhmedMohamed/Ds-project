#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point TopLeft;
	Point LowerRight;
public:
	CEllipse();
	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Load(ifstream& inputfile);
	virtual void Save(ofstream& outputfile);
	virtual void DrawMe(GUI* pOut) const;
};

#endif

