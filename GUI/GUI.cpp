#include "GUI.h"

//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1200;
	UI.height = 800;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 45;
	UI.MenuItemWidth = 60;
	UI.DrawColor = BLACK;	//Drawing color
	UI.IsFilled = false;
	UI.FillColor = IVORY;	//Filling color
	UI.MsgColor = WHITESMOKE;		//Messages color
	UI.BkGrndColor = IVORY;	//Background color
	UI.ToolBarBkGrndColor = WHITE; //toolbar background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = CORNFLOWERBLUE;
	UI.PenWidth = 2;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
	
}


//======================================================================================//
//								Input Functions										    //
//======================================================================================//


void GUI::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType GUI::MapInputToActionType() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			
			
			case ITM_SQUR: return DRAW_SQUARE;
			case ITM_ELPS: return DRAW_ELPS;
			case ITM_HEX:  return DRAW_HEX;
			case ITM_TO_BACK: return SEND_BACK;
			case ITM_TO_FRONT: return BRNG_FRNT;
			case ITM_RESIZE: return RESIZE;
			case ITM_PALETTE: return OPEN_PALETTE_BAR;
			case ITM_CHNG_FILL: return OPEN_FILL_PALETTE_BAR;
			case ITM_CHNG_BK: return OPEN_BKGRND_PALETTE_BAR;
			case ITM_DELETE:  return DEL;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_PLAY: return TO_PLAY;
			case ITM_EXIT: return EXIT;
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_COLOR) {
		//[1] If user clicks on the Toolbar in color mode
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RED: return SET_RED;
			case ITM_GREEN: return SET_GREEN;
			case ITM_BLUE: return SET_BLUE;
			case ITM_YELLOW: return SET_YELLOW;
			case ITM_BACK: return GO_BACK;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_FILL_COLOR) {
		//[1] If user clicks on the Toolbar in color mode
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case ITM_RED: return SET_FILL_RED;
			case ITM_GREEN: return SET_FILL_GREEN;
			case ITM_BLUE: return SET_FILL_BLUE;
			case ITM_YELLOW: return SET_FILL_YELLOW;
			case ITM_BACK: return GO_BACK;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}



		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_BKGRND_COLOR) {
		//[1] If user clicks on the Toolbar in color mode
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case ITM_RED: return SET_BK_RED;
			case ITM_GREEN: return SET_BK_GREEN;
			case ITM_BLUE: return SET_BK_BLUE;
			case ITM_YELLOW: return SET_BK_YELLOW;
			case ITM_BACK: return GO_BACK;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}



		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	
	else if (UI.InterfaceMode == MODE_SIZE)
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case ITM_HALF: return HALF;
			case ITM_QUARTER: return QUARTER;
			case ITM_DOUBLE:   return DOUBLE1;
			case ITM_QUADRUPLE: return QUADRUPLE;
			case ITM_BACK2:  return BACK2;
			}
		}
	}//GUI is in PLAY mode
	else if( UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case ITM_SHAPE: return PLAY_SHAPES;
			case ITM_COLOR: return PLAY_COLORS;
			case ITM_SHAPE_COLOR: return PLAY_SHAPES_COLORS;
			case ITM_PLAY_LOAD:return LOAD;
			case ITM_DRAW_BACK: return GO_BACK;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}



		}

		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}




		return STATUS;	//just for now. This should be updated
	}	

}
//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreateToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() const
{
	//UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SQUR] = "images\\MenuItems\\square.JPG";
	MenuItemImages[ITM_ELPS] = "images\\MenuItems\\ellipse.JPG";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\hexagon.jpg";
	MenuItemImages[ITM_PALETTE] = "images\\MenuItems\\c_p.jpg";
	MenuItemImages[ITM_CHNG_FILL] = "images\\MenuItems\\Menu_FillColor.jpg";
	MenuItemImages[ITM_CHNG_BK] = "images\\MenuItems\\Menu_BKColor.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_TO_BACK] = "images\\MenuItems\\Send_to_Back.jpg";
	MenuItemImages[ITM_TO_FRONT] = "images\\MenuItems\\Menu_Front.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Resize.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(LIGHTBLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////



void GUI::CreateResizeToolBar() const
{
	
	UI.InterfaceMode = MODE_SIZE;

	string MenuItemImages[SIZE_ITM_COUNT];
	MenuItemImages[ITM_HALF] = "images\\MenuItems\\1.jpg";
	MenuItemImages[ITM_QUARTER] = "images\\MenuItems\\2.jpg";
	MenuItemImages[ITM_DOUBLE] = "images\\MenuItems\\3.jpg";
	MenuItemImages[ITM_QUADRUPLE] = "images\\MenuItems\\4.jpg";
	MenuItemImages[ITM_BACK2] = "images\\MenuItems\\Menu_Back_2.jpg";


	///TODO: write code to create Color mode menu
	for (int i = 0; i < SIZE_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth , 0 , UI.MenuItemWidth, UI.ToolBarHeight);


	
	//Draw a line under the toolbar
	pWind->SetPen(LIGHTBLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_SHAPE] = "images\\MenuItems\\shapesss.jpg";
	MenuItemImages[ITM_COLOR] = "images\\MenuItems\\colorss.jpg";
	MenuItemImages[ITM_SHAPE_COLOR] = "images\\MenuItems\\shapes_colors.jpg";
	MenuItemImages[ITM_PLAY_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_DRAW_BACK] = "images\\MenuItems\\Menu_Back.jpg";


	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(LIGHTBLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);	
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int GUI::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void GUI::DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P1.x +length, P1.y+length, style);
	//pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);
	//pWind->DrawEllipse(P1.x, P1.y, P1.x + length, P1.y + length, style);

}

void GUI::DrawEllipse(Point p1, Point p2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	//pWind->DrawRectangle(P1.x, P1.y, P1.x + length, P1.y + length, style);
	pWind->DrawEllipse(p1.x, p1.y, p2.x, p2.y, style);
}
void GUI::DrawHex(Point TopLeft, int Llen, int Rlen, GfxInfo RectGfxInfo, bool selected) const 
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	//2.4- Calculate array of points :
	int hX[6] = { TopLeft.x, TopLeft.x + Llen , TopLeft.x + (1.5 * Llen), (TopLeft.x + Llen), TopLeft.x, abs(TopLeft.x - (0.5 * Llen)) };
	int hY[6] = { TopLeft.y,TopLeft.y, TopLeft.y + Rlen, TopLeft.y + (2 * Rlen), TopLeft.y + (2 * Rlen), abs(TopLeft.y + Rlen) };

	//pWind->DrawRectangle(P1.x, P1.y, P1.x + length, P1.y + length, style);
	pWind->DrawPolygon(hX, hY, 6, style);
}
//======================================================================================//
//							    Change Color Functions										//
// =====================================================================================//
void GUI::ClearToolBar() const
{
	//clear tool bar by drawing filled white square
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.ToolBarBkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}


void GUI::CreateColorToolBar() const {
	//UI.InterfaceMode = MODE_COLOR;
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum ColorMenuItem
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\Menu_Back.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth - 5, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(LIGHTBLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
bool GUI::getColorIsFilled() const {
	if (UI.IsFilled == true) {
		return UI.IsFilled;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

