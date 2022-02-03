#include "ActionPlayWithColors.h"
#include "../ApplicationManager.h"

ActionPlayWithColors::ActionPlayWithColors(ApplicationManager* pApp):Action(pApp)
{

}

void ActionPlayWithColors::Execute()
{
	int* figuresColors = new int[4]{0};
	pManager->getFiguresColors(figuresColors);
	/*for(int i=0;i<4;i++)*/
		

}
