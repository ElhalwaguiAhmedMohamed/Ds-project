#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_COLOR, //coloring mode
	MODE_FILL_COLOR, //fill color mode
	MODE_BKGRND_COLOR, //background color mode
	MODE_SIZE,
	MODE_PLAY	//Playing mode
	
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SQUR,		//Square item in menu
	ITM_ELPS,		//Ellipse item in menu
	ITM_HEX,        //Hex item in menu
	ITM_TO_BACK,
	ITM_TO_FRONT,
	ITM_RESIZE,
	
	ITM_PALETTE,	//Palette Item in menu-change draw color 
	ITM_CHNG_FILL,	//change fill color
	ITM_CHNG_BK,	//change background color
	//TODO: Add more items names here
	ITM_DELETE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_PLAY,
	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};
enum SizeMenuItem // The items of colors
{
	ITM_QUARTER,
	ITM_HALF,
	ITM_DOUBLE,
	ITM_QUADRUPLE,

	ITM_BACK2,

	SIZE_ITM_COUNT
};


enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_SHAPE,
	ITM_COLOR,
	ITM_SHAPE_COLOR,
	ITM_PLAY_LOAD,
	ITM_DRAW_BACK,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum ColorMenuItem
{
	ITM_RED,
	ITM_GREEN,
	ITM_BLUE,
	ITM_YELLOW,
	ITM_BACK,
	COLOR_ITM_COUNT
};



__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	bool IsFilled;			//check if is filled property is true or false
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color ToolBarBkGrndColor; //Toolbar background Height
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif