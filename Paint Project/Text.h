#include "AllShapes.h"
#pragma once

class Text : public AllShapes{

private:

public:
	//constructors
	Text();

	//functions
	void Draw();
	bool contain(int p1, int p2);
	void ChangeColor(int color);
	void SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2);
	void drawtext(char c);
	void fillColor(int c);


};