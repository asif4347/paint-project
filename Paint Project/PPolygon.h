#include "AllShapes.h"

#pragma once

class PPolygon :public AllShapes{
private:
	int PointNumber;

protected:
	int FillColor;

public:
	//constructors
	PPolygon();
	PPolygon(int F, int NOP);

	//functions
	void Draw();
	bool contain(int p1, int p2);
	void SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2);
	void drawtext(char c){};
	void fillColor(int c);
	



};