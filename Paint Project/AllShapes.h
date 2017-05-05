
#pragma once

struct points
{
	float x;
	float y;
};

class AllShapes{

protected:
	points *Points;
	int color;
	int NumOfPoints;
	
public:

	//functions
	virtual bool contain( int p1, int p2 ) = 0;
	virtual void Draw() = 0;
	virtual void drawtext( char c ) = 0;
	virtual void fillColor(int c) = 0;

	//setters
	virtual void SetPoints(int mouse_x1, int mouse_y1, int mouse_x2, int mouse_y2) = 0;
	

	//getters



};