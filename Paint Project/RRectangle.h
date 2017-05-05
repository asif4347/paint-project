#include"PPolygon.h"
#pragma once

class RRectangle :public PPolygon{


public:
	//constructors
	RRectangle();

	//functions
	void Draw();
	void SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2);
	bool contain(int p1, int p2);
	void drawtext(char c){};
	void fillColor(int c);


};