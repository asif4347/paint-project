#include "PPolygon.h"
#pragma once

class Triangle:public PPolygon
{

public:
	//constructors
	Triangle();

	//functions
	void Draw();
	void SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2, int mouse_x3, int mouse_y3);
	bool contain(int p1, int p2);
	void drawtext(char *c){};

};


