#ifndef CELLIPSE_H
#define CELLIPSE_H
#define _USE_MATH_DEFINES
#include "CFigure.h"
#include <math.h>

class CEllipse : public CFigure
{
private:
	Point TopLeft;
	Point LowerRight;
	Point Center;
	int a;
	int b;
	static int ellipseCount ;
public:
	CEllipse();
	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	virtual bool Get(int x, int y) const;
	virtual string ShowFigureDetails() const;
	virtual void Load(ifstream& inputfile);
	virtual void Save(ofstream& outputfile);
	virtual void DrawMe(GUI* pOut) const;
	virtual void Resize(float);
	static  int getCount();
	
};

#endif

