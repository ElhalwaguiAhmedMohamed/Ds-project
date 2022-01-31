#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddEllipse.h"
#include "Actions\ActionDelete.h"
#include "Actions\ActionAddHex.h"
#include "Actions\ActionOpenPalette.h"
#include "Actions\ActionChngColor.h"
#include "Actions\ActionChngFillColor.h"
#include "Actions\ActionChngBkColor.h"
#include "Actions\ActionSwitchToDrawMode.h"
#include "Actions\ActionLoad.h"
#include "Actions/ActionSave.h"
#include "Actions/ActionExit.h"
#include "Actions/ActionSwitchToPlay.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Actions\ActionSelect.h"
#include "Actions\ActionBack.h"
#include "Actions\ActionFront.h"


//Constructor
ApplicationManager::ApplicationManager() : mode(0)
{
	//Create Input and output
	pGUI = new GUI;	
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{	
		///step1:Map input to action type
		//1- Read user action
		ActType = pGUI->MapInputToActionType(); ///this function checks wich menu itme is clicked by chckeing the (x,y) coordinates of the mouse ///returns enum value

		///step2: create corresponding action
		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType); ///this function is down in this file called to do the action ///returns new action and points to it to use it for execution in the next function
		
		///step3:Execute the action
		//3- Execute the action
		ExecuteAction(pAct); //

		//4- Update the interface
		UpdateInterface();	

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;  //for polymorphism so that I acn use it with different actions
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this); ///the ActionAddSquare takes a pointer of the type ApplicationManager*
			break;

		case DRAW_ELPS:
			///create AddLineAction here
			newAct = new ActionAddEllipse(this);
			break;

		case DRAW_HEX:
			newAct = new ActionAddHex(this);
			break;
		case OPEN_PALETTE_BAR:
			newAct = new ActionOpenPalette(this,1);
			break;
		case SET_RED:
			newAct = new ActionChngColor(this, 1);
			break;
		case SET_GREEN:
			newAct = new ActionChngColor(this, 2);
			break;
		case SET_BLUE:
			newAct = new ActionChngColor(this, 3);
			break;
		case SET_YELLOW:
			newAct = new ActionChngColor(this, 4);
			break;
		case GO_BACK:
			newAct = new ActionSwitchToDrawMode(this);
			break;
		case OPEN_FILL_PALETTE_BAR:
			newAct = new ActionOpenPalette(this, 2);
			break;
		case SET_FILL_RED:
			newAct = new ActionChngFillColor(this, 1);
			break;
		case SET_FILL_GREEN:
			newAct = new ActionChngFillColor(this, 2);
			break;
		case SET_FILL_BLUE:
			newAct = new ActionChngFillColor(this, 3);
			break;
		case SET_FILL_YELLOW:
			newAct = new ActionChngFillColor(this, 4);
			break;
		case OPEN_BKGRND_PALETTE_BAR:
			newAct = new ActionOpenPalette(this, 3);
			break;
		case SET_BK_RED:
			newAct = new ActionChngBkColor(this, 1);
			break;
		case SET_BK_GREEN:
			newAct = new ActionChngBkColor(this, 2);
			break;
		case SET_BK_BLUE:
			newAct = new ActionChngBkColor(this, 3);
			break;
		case SET_BK_YELLOW:
			newAct = new ActionChngBkColor(this, 4);
			break;

		case DEL:
			newAct = new ActionDelete(this);
			break;

		case DRAWING_AREA:
			newAct = new ActionSelect(this);
			break;

		case SAVE:
			newAct = new ActionSave(this);
			break;
		case LOAD:
			newAct = new ActionLoad(this);
			break;

		case EXIT:
			///create ExitAction here
			newAct = new ActionExit(this);
			break;

		case BRNG_FRNT:
			newAct = new ActionBringFront(this);
			break;

		case SEND_BACK :
			newAct = new SendBack(this);
			break;
		case RESIZE:
			newAct = new ActionResize(this, SelectedFig);
			break;

		
		case TO_PLAY:
			newAct = new ActionSwitchToPlay(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;


	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
void ApplicationManager::SaveAll(ofstream &outputfile)
{
	// Figure save Functions Run
	if (outputfile.is_open())
	{
		outputfile << to_string(FigCount) << "\n";
		for (int i = 0; i < FigCount; i++)
		{
			FigList[i]->Save(outputfile);
		}
	}
	
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
CFigure** ApplicationManager::getFigList(){
	return FigList;
};
int* ApplicationManager::getFigCount() {
	return &FigCount;
};
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = FigCount - 1; i >= 0; i--)
		if (FigList[i]->Get(x, y))
			return FigList[i];
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetSelectedFigure() const
{
	//check if a figure selected
 	for (int i = (FigCount - 1); i >= 0; i--) {
		if (FigList[i]->IsSelected()) return FigList[i];
	}
	return NULL;
}
void ApplicationManager::set_selected(CFigure* fig)   //set the selcted figure. We need it on copy, cut, paste and delete actions
{
	SelectedFig = fig;
}

void ApplicationManager::Unselect(CFigure* fig)  // Select the last figures ONLY
{
	for (int i = 0; i < FigCount; ++i)
		if (FigList[i] != fig)
		{
			FigList[i]->SetSelected(false);
			FigList[i]->assignStored();
		}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)

	
	if (UI.InterfaceMode == MODE_DRAW)
	{

		pGUI->CreateDrawToolBar();
	}
	else if (UI.InterfaceMode == MODE_SIZE) {
		pGUI->CreateResizeToolBar();
		
	}
	
}
void ApplicationManager::DeleteList() {
	for (int i = 0; i < FigCount; i++)
		FigList[i]==NULL;
	FigCount = 0;
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}
void ApplicationManager::set_LastMessage(string s)
{
	LastMessage = s;
}
//==================================================================================//
//							Send To Back											//
//==================================================================================//

void ApplicationManager::SendToBack(int selectedIndex)
{
	if (selectedIndex != 0)
	{
		CFigure* spare = FigList[0];
		FigList[0] = FigList[selectedIndex];
		FigList[selectedIndex] = spare;
	}
}
//==================================================================================//
//							Bring To Front											//
//==================================================================================//

void ApplicationManager::BringToFront(int selectedIndex)
{
	if (selectedIndex != FigCount - 1)
	{
		CFigure* temp = FigList[FigCount - 1];
		FigList[FigCount - 1] = FigList[selectedIndex];
		FigList[selectedIndex] = temp;
	}
}

int ApplicationManager::getSelectedFigure()
{

	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsSelected())
			return i;
	return -1;
}

