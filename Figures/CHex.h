
#ifndef CHex_H
#define CHex_H

#include "CFigure.h"

class CHex : public CFigure
{
private:
	Point TopLeft;
	int Llen;
	int Rlen;
	int length;
	Point Center;
	static int hexCount;

public:
	CHex();
	CHex(Point, int, int, GfxInfo FigureGfxInfo);
	virtual bool Get(int x, int y) const;
	static int getCount();
	virtual string ShowFigureDetails() const;
	virtual void Load(ifstream& inputfile);
	virtual void Save(ofstream& outputfile);
	virtual void DrawMe(GUI* pOut) const;
	virtual void Resize(float);


};

#endif

