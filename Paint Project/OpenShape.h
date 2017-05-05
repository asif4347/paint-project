#include "AllShapes.h"
#pragma once

class OpenShape :public AllShapes{

protected:
	bool style;

public:

	//functions
	virtual bool contain(int p1, int p2) = 0;
	virtual void Draw() = 0;
	void drawtext(char c){};
	virtual void fillColor(int c) = 0;

	//setters
	virtual void SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2) = 0;



};