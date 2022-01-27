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

	if (fig != NULL) {

		if (fig->IsSelected()) {
			fig->ChngDrawClr(fig->ChngSelectClr());
			fig->SetSelected(false);
			pGUI->PrintMessage("unselected");
		}
		else{
			fig->ChngSelectClr(fig->GetCurrentDrawClr());
			fig->ChngDrawClr(MAGENTA);
			fig->SetSelected(true);
			pGUI->PrintMessage("selected");
		}
	}
	else {

		CFigure* selectedFiguer = pManager->GetSelectedFigure();
		if (selectedFiguer != NULL) {
			selectedFiguer->ChngDrawClr(selectedFiguer->ChngSelectClr());
			selectedFiguer->SetSelected(false);
			pGUI->PrintMessage("unselected");
		}
	}
}
