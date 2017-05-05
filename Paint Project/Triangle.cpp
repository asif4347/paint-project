#include "Triangle.h"
#include "GP142.H"

#pragma once

Triangle::Triangle()
{
	FillColor = 1;
	Points = new points[3];
}

void Triangle::SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2, int mouse_x3, int mouse_y3)
{
	

	Points[0].x = mouse_x1;
	Points[0].y = mouse_y1;

	Points[1].x = mouse_x2;
	Points[1].y = mouse_y2;

	Points[2].x = mouse_x3;
	Points[2].y = mouse_y3;

}

bool Triangle::contain(int p1, int p2)
{
	return false;
}

void Triangle::Draw()
{
	//draws four lines for rectangle

	GP142_lineXY(FillColor, Points[0].x, Points[0].y, Points[1].x, Points[1].y, 1);
	GP142_lineXY(FillColor, Points[1].x, Points[1].y, Points[2].x, Points[2].y, 1);
	GP142_lineXY(FillColor, Points[2].x, Points[2].y, Points[0].x, Points[0].y, 1);

}