#include "ActionOpenPalette.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionOpenPalette::ActionOpenPalette(ApplicationManager* pApp,int modeFlag) :Action(pApp)
{
	Mode = modeFlag;
}

//Execute the action
void ActionOpenPalette::Execute()
{
	//Get a Pointer to the Interface
	switch (Mode) {
	case 1:
		UI.InterfaceMode = MODE_COLOR;
		break;
	case 2:
		UI.InterfaceMode = MODE_FILL_COLOR;
		break;
	case 3:
		UI.InterfaceMode = MODE_BKGRND_COLOR;
		break;
	};
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearToolBar();
	pGUI->CreateColorToolBar();

}
