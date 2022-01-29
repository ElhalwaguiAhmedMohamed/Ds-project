#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include <fstream>
#include"Actions/ActionResize.h"
class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount,mode;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	//Pointers to Input and Output classes
	GUI* pGUI;
	string LastMessage;
	CFigure* SelectedFig; //Pointer to the selected figure


public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action

	
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* GetSelectedFigure() const;
	void SaveAll(ofstream&);
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window
	void set_selected(CFigure*); //Setting Selected
	void Unselect(CFigure*);   //Unselect all figures except a paritcular figure
	void DeleteList();
	

	void ApplicationManager::SendToBack(int selectedIndex);

	void ApplicationManager::BringToFront(int selectedIndex);

	void set_LastMessage(string); // saving the last message
	

	int ApplicationManager::getSelectedFigure();
	void Resize();

	
};

#endif