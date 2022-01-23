
#ifndef CHex_H
#define CHex_H

#include "CFigure.h"

class CHex : public CFigure
{
private:
	Point TopLeft;
	int Llen;
	int Rlen;

public:
	CHex();
	CHex(Point, int, int, GfxInfo FigureGfxInfo);
	virtual void Load(ifstream& inputfile);
	virtual void DrawMe(GUI* pOut) const;

};

#endif

