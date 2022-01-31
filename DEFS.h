#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_SQUARE,	//Draw a Square
	DRAW_ELPS,		//Draw an Ellipse
	DRAW_HEX,		//Draw a Hexagon
	OPEN_PALETTE_BAR, //Draw palette bar
	SET_RED,		  //set color to red
	SET_GREEN,		  //set color to green
	SET_BLUE,		  //set color to blue
	SET_YELLOW,		  //set color to yellow
	GO_BACK,		  //send to back and switch back to draw mode
	OPEN_FILL_PALETTE_BAR, // Open fill palette bar
	SET_FILL_RED,	  //Set fill color to red
	SET_FILL_GREEN,	  //Set fill color to green
	SET_FILL_BLUE,	  //Set fill color to blue
	SET_FILL_YELLOW,  //Set fill color to yellow
	OPEN_BKGRND_PALETTE_BAR, //Open change background color bar
	SET_BK_RED,		  //Set background color to red
	SET_BK_GREEN,	  //Set background color to green
	SET_BK_BLUE,	  //Set background color to blue
	SET_BK_YELLOW,	  //Set background color to yellow
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	PLAY_SHAPES,    //play with only shapes
	PLAY_COLORS,	//play with only colors
	PLAY_SHAPES_COLORS, //PLay with shapes and colors
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode

	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color PreviousClr; //save color of figure before selection 
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth = 2;	//Width of figure borders

};

#endif