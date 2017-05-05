#include "RRectangle.h"
#include "GP142.H"

#pragma once

RRectangle::RRectangle()
{
	FillColor = 1;
	color = 1;
}

void RRectangle::SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2)
{
	Points = new points[2];

	Points[0].x = mouse_x1;
	Points[0].y = mouse_y1;

	Points[1].x = mouse_x2;
	Points[1].y = mouse_y2;
}

bool RRectangle::contain(int p1, int p2)
{


	return true;
}

void RRectangle::Draw()
{
	GP142_lineXY(color, Points[0].x, Points[0].y, Points[0].x, Points[1].y, 1); // draws rectangle
	GP142_lineXY(color, Points[0].x, Points[1].y, Points[1].x, Points[1].y, 1);
	GP142_lineXY(color, Points[1].x, Points[1].y, Points[1].x, Points[0].y, 1);
	GP142_lineXY(color, Points[0].x, Points[0].y, Points[1].x, Points[0].y, 1);


}


void RRectangle::fillColor(int c)
{
	int y1 = 0, y2 = 0;
	if (Points[0].y > Points[1].y)
		y1 = Points[0].y;
	else
		y1 = Points[1].y;

	int dist = 0;
	dist = Points[1].y - Points[0].y;

	if (dist < 0)
		dist = dist * -1;

	for (int i = 1; i <= dist+1; i++)
	{
		GP142_lineXY(c, Points[0].x, y1, Points[1].x, y1, 1);
		y1--;
	}
}