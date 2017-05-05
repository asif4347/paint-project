#include "Line.h"
#include "GP142.H"

#pragma once

Line::Line()
{
	style = false;
	Points = new points[2];
	color = 1;
	NumOfPoints = 2;
}

void Line::ChangeColor(int col)
{
	color = col;
}

void Line::SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2)
{
	Points[0].x = mouse_x1;
	Points[0].y = mouse_y1;

	Points[1].x = mouse_x2;
	Points[1].y = mouse_y2;
}

void Line::Draw()
{
	if (style == false)
		GP142_lineXY(color, Points[0].x, Points[0].y, Points[1].x, Points[1].y, 1);
	else if (style == true)
	{
	}
}

bool Line::contain(int x, int y)
{
	return false;
}

void Line::fillColor(int c)
{

}