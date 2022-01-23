#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\LoadAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	//Bla Bla Bla
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

			break;

		case LOAD:
			newAct = new LoadAction(this);
			break;
		case EXIT:
			///create ExitAction here
			
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
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
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


	///Add your code here to search for a figure given a point x,y	

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
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
