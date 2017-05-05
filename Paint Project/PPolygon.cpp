#include "PPolygon.h"
#include "GP142.H"

#pragma once



PPolygon::PPolygon()
{
	PointNumber = 0;
}

PPolygon::PPolygon(int F, int NOP)
{
	PointNumber = 0;
	FillColor = F;
	NumOfPoints = NOP;
	Points = new points[NumOfPoints];
}

void PPolygon::SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2)
{
	
	Points[PointNumber].x = mouse_x1;
	Points[PointNumber].y = mouse_y1;
	
	PointNumber++;
}

void PPolygon::Draw()
{
	int count = 0;
	int j = 0;

	while (count < NumOfPoints - 1)
	{
		GP142_lineXY(color, Points[j].x, Points[j].y, Points[j + 1].x, Points[j + 1].y, 1);
		j++;
		count++;
	}
	
	GP142_lineXY(color, Points[j].x, Points[j].y, Points[0].x, Points[0].y, 1);

}

bool PPolygon::contain(int p1, int p2)
{
	return false;
}

void PPolygon::fillColor(int c)
{

}