#include "Circle.h"
#include "GP142.H"
#include <math.h>

#pragma once

Circle::Circle()
{
	Points = new points[2];

	Points[0].x = 0;
	Points[0].y = 0;
	Points[1].x = 0;
	Points[1].y = 0;

	radius = 0;
	FillColor = 0;
}

Circle::Circle(int R, int F)
{

	radius = R;
	FillColor = F;
	Points = new points[2];

}

void Circle::SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2)
{
	Points[0].x = mouse_x1;
	Points[0].y = mouse_y1;

	Points[1].x = mouse_x2;
	Points[1].y = mouse_y2;
}




void Circle::Draw()
{
	radius = sqrt(((Points[1].x - Points[0].x)*(Points[1].x - Points[0].x)) + ((Points[1].y - Points[0].y)*(Points[1].y - Points[0].y)));

	//printf("%d", radius);

	GP142_circleXY(1, Points[0].x , Points[0].y , radius);
	GP142_circleXY(0, Points[0].x, Points[0].y, radius-1);
}



bool Circle::contain(int p1, int p2)
{
	int distance = 0;

	distance = sqrt((p2 - Points[0].y)*(p2 - Points[0].y) + (p1 - Points[0].x)*(p1 - Points[0].x));

	if (distance <= radius)
		return true;
	else
		return false;
}

void Circle::fillColor(int c)
{
	GP142_circleXY(c, Points[0].x, Points[0].y, radius - 1);
}