#include "Curve.h"
#include "GP142.H"

#pragma once

Curve::Curve()
{

}
Curve::Curve(int NOP)
{
	color = 1;
	NumOfPoints = NOP;
	style = false;
	p = 0;

	Points = new points[NumOfPoints];

}

void Curve::SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2)
{

	Points[p].x = mouse_x1;
	Points[p].y = mouse_y1;

	p++;
}

void Curve::ChangeColor(int col)
{
	color = col;
}

void Curve::Draw()
{
	int count = 0;
	int j = 0;

	while (count <= NumOfPoints)
	{
		GP142_lineXY(color, Points[j].x, Points[j].y, Points[j + 1].x, Points[j + 1].y, 1);
		j++;
		count++;
	}

}

bool Curve::contain(int x, int y)
{
	return false;
}

void Curve::fillColor(int c)
{

}