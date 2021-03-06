#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"

//Base class for all figures
class CFigure
{
protected:
	static int MainID;
	char shapeType;
	int ID;	//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.
	color storedDraw, storedFill;
	bool IsFilled;

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	void setStored();
	virtual bool Get(int x, int y) const = 0;	//Check if the point inside The Figure
	virtual string ShowFigureDetails() const = 0;	//show figure details
	virtual void DrawMe(GUI*) const  = 0;	//Draw the figure
	virtual void Save(ofstream&) = 0; //Save Figure
	virtual void Load(ifstream&) = 0;	 // Load Figure
	virtual color StringToColor(string s) ;
	color virtual GetCurrentDrawClr();	//Get the current figure's fill color
	color virtual GetCurrentFillClr();
	void ChngSelectClr(color Dclr);	//changes the figure's selection color
	color ChngSelectClr();	//changes the figure's selection color
	string ColorToString(color c);
	void virtual ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void virtual ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual void Resize(float) = 0;
	//virtual string PrintInfo(GUI* pOut) = 0;	//print all figure info on the status bar
	void assignStored();
	char getShapeType();
	void setSize(float);
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure

	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif