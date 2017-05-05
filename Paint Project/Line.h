#include "OpenShape.h"

#pragma once

class Line : public OpenShape{

public:
	//constructors
	Line();

	//functions
	void Draw();
	bool contain( int p1, int p2 );
	void ChangeColor(int color);
	void drawtext(char c){};
	void fillColor(int c);

	//setters
	void SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2);



};