#include "ActionSelect.h"

#include "..\ApplicationManager.h"


ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp) ///constructor chaining
{}

void ActionSelect::Execute()
{
	int cx;
	int cy;

	GUI* pGUI = pManager->GetGUI();

	pGUI->GetPointClicked(cx, cy);

	CFigure* fig = pManager->GetFigure(cx,cy);
	if (UI.InterfaceMode != MODE_PLAY)
	{
		if (fig != NULL) {

			if (fig->IsSelected()) {
				fig->ChngDrawClr(fig->ChngSelectClr());
				fig->SetSelected(false);
				pGUI->ClearStatusBar();
			}
			else {
				fig->ChngSelectClr(fig->GetCurrentDrawClr());
				fig->ChngDrawClr(MAGENTA);
				fig->SetSelected(true);
				pGUI->PrintMessage(fig->ShowFigureDetails());

			}
		}
		else {

			CFigure* selectedFigure = pManager->GetSelectedFigure();
			if (selectedFigure != NULL) {
				selectedFigure->ChngDrawClr(selectedFigure->ChngSelectClr());
				selectedFigure->SetSelected(false);
				pGUI->ClearStatusBar();
			}
		}
	}
	else
	{

		if (fig != NULL) {

			fig->ChngSelectClr(fig->GetCurrentDrawClr());
			fig->ChngDrawClr(MAGENTA);
			fig->SetSelected(true);
			Action* newAct = new ActionDelete(pManager);
			newAct->Execute();
		}
	}
	
}
