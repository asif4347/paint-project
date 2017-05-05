#include "Text.h"
#include "GP142.H"
#pragma once

Text::Text()
{
	Points = new points[1];
}



void Text::SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2)
{
	

	Points[0].x = mouse_x1;
	Points[0].y = mouse_y1;

	NumOfPoints = 1;
}


void Text::ChangeColor( int C )
{
	color = C;
}

bool Text::contain(int p1, int p2)
{
	return false;
}

void Text::Draw()
{
	//dummy function
}

void Text::drawtext( char c )
{
	//GP142_textXY(color, Points[0].x, Points[0].y, 20, c);
	GP142_printfXY(color, Points[0].x, Points[0].y, 20, "%c" ,c);
}

void Text::fillColor(int c)
{

}