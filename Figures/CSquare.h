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
	static int squareCount ;
	Point Center;
public:
	CSquare();
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	virtual string ShowFigureDetails() const;
	virtual bool Get(int x, int y) const;
	virtual void Save(ofstream& outputfile);
	virtual void Load(ifstream& inputfile);
	virtual void DrawMe(GUI* pOut) const;
	virtual void Resize(float);
	static int getCount();
};

#endif