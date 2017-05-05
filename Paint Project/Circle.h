#include "AllShapes.h"

#pragma once

class Circle : public AllShapes{

private:
	int radius;
	int FillColor;

public:
	//constructors
	Circle();
	Circle(int R, int F);

	//functions
	void Draw();
	bool contain(int p1, int p2);
	void drawtext(char c){};
	void fillColor(int c);

	//setters
	void SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2);

	//getters
	
};