#include "ActionResize.h"

ActionResize::ActionResize(ApplicationManager *pApp,CFigure *selected):Action(pApp), Selected(selected)
{

}
void ActionResize::ReadActionParameters() {

}
void ActionResize::Execute()
{
	GUI* pGui = pManager->GetGUI();

	pGui->CreateNewToolBar();

	if (Selected != NULL)
	{
		ActionType pAct = pGui ->MapInputToActionType();
		if (pAct == HALF)
		{
			Selected->setSize(.5);
			Selected->Resize(.5);
			//pManager->set_LastMessage(Selected->PrintInfo(pGui));
			pManager->UpdateInterface();
			Execute();
		}
		else if (pAct == QUARTER)
		{
			Selected->setSize(.25);
			Selected->Resize(.25);
			//pManager->set_LastMessage(Selected->PrintInfo(pGui));
			pManager->UpdateInterface();
			this->Execute();
		}
		else if (pAct == DOUBLE1)
		{
			Selected->setSize(2);
			Selected->Resize(2);
			//pManager->set_LastMessage(Selected->PrintInfo(pGui));
			pManager->UpdateInterface();
			this->Execute();
		}
		else if (pAct == QUADRUPLE)
		{
			Selected->setSize(4);
			Selected->Resize(4);
			//pManager->set_LastMessage(Selected->PrintInfo(pGui));
			pManager->UpdateInterface();
			this->Execute();
		}
		else if (pAct == BACK2)
		{
			pManager->CreateAction(BACK);
			pManager->set_selected(NULL);
			pManager->Unselect(NULL);
			pManager->set_LastMessage("");
			return;
		}
	}
	else
		pManager->set_LastMessage("Firstly, Select a fig");
}

