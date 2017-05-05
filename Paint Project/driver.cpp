/*
 * CSE/ENGR 142 GP142_Demo
 *
 * 1/25/95
 * Author(s):         Larry Ruzzo
 * Email Address(s):  ruzzo@cs.washington.edu
 *
 * This program is a demo of some of the features of 
 * GP142 --- the CSE/ENGR 142 Graphics Package.
 * It includes simple drawing commands, keyboard and mouse 
 * interaction, and a simple animation.
 *
 * Revision history:
 * 11/18/97 Dan Boren  - Removed calls to obsolete function GP142_undo()
 *      
 */
#include<string>
#include <fstream>
#include <vector>
#include "AllShapes.h"
#include "Circle.h"
#include "Text.h"
#include "RRectangle.h"
#include "PPolygon.h"
#include "OpenShape.h"
#include "Line.h"
#include "Curve.h"

#include "GP142.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define PI 3.1415926535
#define ANIMATE_MSG "Select \"Animate\"\nOn the \"Run\" Menu"
#define TEXT_SIZE 20

using namespace std;



//You will use the following 5 functions do to all work

//A) DRAWING FUNCTIONS
//the two drawing functions that you will use to make all shapes
void draw_line(int x1, int y1, int x2, int y2, int color=WHITE, int width=1){
	GP142_lineXY (color,x1,y1,x2,y2,width);
}

void draw_circle(int x, int y, int radius, int color=WHITE){
	 GP142_circleXY(color, x, y, radius);
}

//B) EVENT HANDLERS
//Mouse handler
void demo_handle_mouse(int x, int y){
    printf("Left Mouse clicked at (%d,%d)\n", x, y);
	//GP142_printfXY(1, x, y, 10, "(%d,%d)",x,y);
    //GP142_printfXY(YELLOW,x,y,9,"Mouse at (%d,%d)", x, y);
     //draw_circle(x, y, 10);
}

void demo_handle_mouser(int x, int y){
	printf("Right Mouse clicked at (%d,%d)\n", x, y);
	//GP142_printfXY(YELLOW,x,y,9,"Mouse at (%d,%d)", x, y);
	//draw_circle(x, y, 10);
}

void printinator(char arr[])
{
	printf(arr);
}

//Keyboard handler
void demo_handle_kbd(char c)
{
	//put the character anywhere you want to.
	//I'm putting it on the origin
	GP142_printfXY(BLACK, 0, 0,   TEXT_SIZE, "%c", c);
}

//periodic handler you will not need to use because we're not doing animation
void demo_handle_periodic(void){};


/******************************************************************************
 *
 * The Main Program
 * ----------------
 *
 * The main program takes care of initialization and cleanup, and the high-level
 * control of all actions in the program, but most of the detail work is 
 * relegated to sub-functions, so that the structure of main stays clear and 
 * simple.
 *
 */
int main(void)
{
	int quit = 0;           /* has user signaled quit yet?                      */
	int mouse_x, mouse_y;
	char key_pressed;
	GP142_open();           /* Open and initialize the GP142 Graphics Window    */

	int pcount = 0;
	int points[50];
	int PolygonPoints[50];
	int CurvePoints[50];


	for (int x = 0; x < 50; x++)
	{
		PolygonPoints[x] = 1000;
		CurvePoints[x] = 1000;
	}

	vector <AllShapes *> obj;
	
	
	AllShapes* arr[6];
	arr[0] = new Circle;
	arr[1] = new Text;
	arr[2] = new RRectangle;
	//arr[3] = new Curve;
	//arr[4] = new PPolygon;
	arr[5] = new Line;


	int rectangledrawn = 0;
	int bucket = 0;
	int c1 = 0;
	int c2 = 0;
	int key = 0;
	int circle = 0;
	int line = 0;
	int select = 0;
	int text = 0;
	int rectangle = 0;
	int triangle = 0;
	int polygon = 0;
	int contain = 0;
	int circledrawn = 0;
	int curve = 0;
	int CPcount = 0;
	int PPcount = 0;
	int ip = 0;
	int ic = 0;
	int FILL = 0;
	int dotLine = 0;
	int save = 0;
	int load = 0;
	int saveCount = 0;
	int indexCircle = 0;
	int indexRect = 0;
	int indexLine = 0;
	int indexCurve = 0;
	int indexPoly = 0;
	int saved = 0;

	//The Event Loop  
	while (!quit) {

		
		//================================== PANEL ========================================

		draw_line(-300, -300, -300, 300); //vertical line

		draw_line(-400, 0, -300, 0); //circle
		draw_circle(-350, 25, 15); 
		draw_circle(-350, 25, 14, BLACK);

		draw_line(-400, 50, -300, 50); //line
		draw_line(-370, 75, -325, 75); 

		draw_line(-400, 100, -300, 100); //Text
		draw_line(-360, 140, -340, 140);
		draw_line(-350, 140, -350, 110);


		draw_line(-400, 150, -300, 150); //rectangle
		draw_line(-370, 170, -330, 170); 
		draw_line(-370, 185, -330, 185); 
		draw_line(-370, 170, -370, 185);
		draw_line(-330, 170, -330, 185);

		
		draw_line(-400, 200, -300, 200);//curve
		draw_line(-360, 235, -360, 215);
		draw_line(-360, 235, -340, 235);
		draw_line(-360, 215, -340, 215);


		draw_line(-400, 250, -300, 250); //Polygon
		draw_line(-360, 280, -360, 260);
		draw_line(-360, 280, -340, 280);
		draw_line(-340, 280, -340, 270);
		draw_line(-340, 270, -360, 270);

		draw_line(-400, -50, -300, -50); //contain
		GP142_textXY(1, -375, -33, 15, "Contain");

		draw_line(-400, -100, -300, -100);
		GP142_textXY(1, -365, -83, 15, "- - - -");


		GP142_textXY(1, -370, -120, 15, "Colors");
		draw_line(-400, -125, -300, -125);

		
		
		draw_line(-400, -150, -300, -150);
		draw_line(-400, -175, -300, -175);
		draw_line(-400, -200, -300, -200);
		draw_line(-400, -225, -300, -225);
		draw_line(-400, -250, -300, -250);
		draw_line(-350, -125, -350, -250);

		GP142_printfXY(5, -385, -275, 10, "SAVE");
		GP142_printfXY(3, -340, -275, 10, "LOAD");
		draw_line(-350, -250, -350, -300);

		int l1 = -150;
		while ( l1 > -175 )
		{
			draw_line(-400, l1, -350, l1, 1, 1);
			l1--;
		}

		int l2 = -175;
		while (l2 > -200)
		{
			draw_line(-400, l2, -350, l2, 2, 1);
			l2--;
		}
		
		int l3 = -200;
		while (l3 > -225)
		{
			draw_line(-400, l3, -350, l3, 3, 1);
			l3--;
		}

		int l4 = -225;
		while (l4 > -250)
		{
			draw_line(-400, l4, -350, l4, 4, 1);
			l4--;
		}

		l1 = -150;
		while (l1 > -175)
		{
			draw_line(-350, l1, -300, l1, 5, 1);
			l1--;
		}

		l2 = -175;
		while (l1 > -200)
		{
			draw_line(-350, l1, -300, l1, 6, 1);
			l1--;
		}

		l3 = -200;
		while (l1 > -225)
		{
			draw_line(-350, l1, -300, l1, 7, 1);
			l1--;
		}

		l4 = -225;
		while (l1 > -250)
		{
			draw_line(-350, l1, -300, l1, 13, 1);
			l1--;
		}

		//======================================= PANEL END ==================================

		switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) {
		case GP142_QUIT:
			quit = 1;   /* set flag to terminate loop                */
			break;

		case GP142_MOUSE:


			printinator("LEFT CLICKED");
			demo_handle_mouse(mouse_x, mouse_y);
			if (select == 0) // panel selection
			{

				if (mouse_x < -300 && mouse_y > 0 && mouse_y < 50)
				{
					circle = 1; //flag to initiate the circle function
					select = 1;
					
					printf("Circle");
					break;
				}
				else if (mouse_x < -300 && mouse_y > 50 && mouse_y < 100)
				{
					line = 1; //flag to initiate the line function
					select = 1;
					printf("%d", line);
					break;
				}
				else if (mouse_x < -300 && mouse_y > 100 && mouse_y < 150)
				{
					text = 1; //flag to initiate the text function
					select = 1;
					printf("%d", text);
					break;
				}
				else if (mouse_x < -300 && mouse_y > 150 && mouse_y < 200)
				{
					rectangle = 1; //flag to initiate the circle function
					select = 1;
					printf("%d", rectangle);
					break;
				}
				else if (mouse_x < -300 && mouse_y > 200 && mouse_y < 250)
				{
					curve = 1; //flag to initiate the curve function
					select = 1;
					printf("%d", curve);
					break;
				}
				else if (mouse_x < -300 && mouse_y > 250 && mouse_y < 300)
				{
					polygon = 1; //flag to initiate the circle function
					select = 1;
					printf("%d", polygon);
					break;
				}
				else if (mouse_x < -300 && mouse_y < 0 && mouse_y > -50)
				{
					contain = 1; //flag to initiate the circle function
					select = 1;
					printf("%d", polygon);
					break;
				}
				else if (mouse_x < -350 && mouse_y < -150 && mouse_y > -175)
				{
					FILL = 1; //flag to initiate the circle function
					bucket = 1;
					select = 1;
					//GP142_printfXY(1, 0, 0, 15, "COLOR SELECTED");
					printf("%d", contain);
					break;
				}
				else if (mouse_x < -350 && mouse_y < -175 && mouse_y > -200)
				{
					FILL = 1; //flag to initiate the circle function
					bucket = 2;
					select = 1;
					//GP142_printfXY(1, 0, 0, 15, "COLOR SELECTED");
					printf("%d", contain);
					break;
				}
				else if (mouse_x < -350 && mouse_y < -200 && mouse_y > -225)
				{
					FILL = 1; //flag to initiate the circle function
					bucket = 3;
					select = 1;
					//GP142_printfXY(1, 0, 0, 15, "COLOR SELECTED");
					printf("%d", contain);
					break;
				}
				else if (mouse_x < -350 && mouse_y < -225 && mouse_y > -250)
				{
					FILL = 1; //flag to initiate the circle function
					bucket = 4;
					select = 1;
					//GP142_printfXY(1, 0, 0, 15, "COLOR SELECTED");
					printf("%d", contain);
					break;
				}
				else if (mouse_x < -300 && mouse_x > -350 && mouse_y < -150 && mouse_y > -175)
				{
					FILL = 1; //flag to initiate the circle function
					bucket = 5;
					select = 1;
					//GP142_printfXY(1, 0, 0, 15, "COLOR SELECTED");
					printf("%d", contain);
					break;
				}
				else if (mouse_x < -300 && mouse_x > -350 && mouse_y < -175 && mouse_y > -200)
				{
					FILL = 1; //flag to initiate the circle function
					bucket = 6;
					select = 1;
					//GP142_printfXY(1, 0, 0, 15, "COLOR SELECTED");
					printf("%d", contain);
					break;
				}
				else if (mouse_x < -300 && mouse_x > -350 && mouse_y < -200 && mouse_y > -225)
				{
					FILL = 1; //flag to initiate the circle function
					bucket = 7;
					select = 1;
					//GP142_printfXY(1, 0, 0, 15, "COLOR SELECTED");
					printf("%d", contain);
					break;
				}
				else if (mouse_x < -300 && mouse_x > -350 && mouse_y < -225 && mouse_y > -250)
				{
					FILL = 1; //flag to initiate the circle function
					bucket = 13;
					select = 1;
					//GP142_printfXY(1, 0, 0, 15, "COLOR SELECTED");
					printf("%d", contain);
					break;
				}
				else if (mouse_x < -350 && mouse_x > -400 && mouse_y < -250)
				{
					save = 1; //flag to initiate the save function
					select = 1;
					//GP142_printfXY(1, 0, 0, 15, "SAVE SELECTED");
					printf("%d", contain);
					break;
				}
				else if (mouse_x < -300 && mouse_x > -350 && mouse_y < -250)
				{
					load = 1; //flag to initiate the circle function
					ifstream ifile("Save.pb");
					int sts=0;
					string sss;
					while(!ifile.eof()){
					ifile>>sss;
					sts++;
					}
					for(int i=0;i<sts;i++){
					}
					select = 1;
					//GP142_printfXY(1, 0, 0, 15, "LOAD SELECTED");
					printf("%d", contain);
					break;
				}
				else if (mouse_x < -300 && mouse_y < -50 && mouse_y > -100)
				{
					dotLine = 1; //flag to initiate the circle function
					select = 1;
					//GP142_printfXY(1, 0, 0, 15, "DOT LINE SELECTED");
					printf("%d", contain);
					break;
				}
				
		//===================================================================================================================//

			}
			else if (select == 1) //draw functions
			{
				if (polygon == 1)
				{
					PolygonPoints[2 * PPcount] = mouse_x;
					PolygonPoints[2 * PPcount + 1] = mouse_y;
					PPcount++;	
				}
			
				else if (curve == 1)
				{
					CurvePoints[2 * CPcount] = mouse_x;
					CurvePoints[2 * CPcount + 1] = mouse_y;
					CPcount++;
				}
				else if (save == 1)
				{
					ofstream OutputFile("Save.pb");
					if (OutputFile.is_open() == TRUE)
					{

						for (int i = 0; i < obj.size(); i++)
							OutputFile << obj[i] << endl;
					}

					GP142_printfXY(1,0,0,15,"SAVED SUUCCESSFULLY!");
					saved = 1;

					

				}
				else
				{

					points[2 * pcount] = mouse_x;
					points[2 * pcount + 1] = mouse_y;
					pcount++;

					if (pcount == 2 && circle == 1)
					{

					//object
						obj.push_back(new Circle);
						indexCircle = obj.size() - 1;

						obj[indexCircle]->SetPoints(points[0], points[1], points[2], points[3]); //SetPoints
						obj[indexCircle]->Draw();
						pcount = 0;
						select = 0;
						circle = 0;
						circledrawn = 1;
					}
					if (pcount == 2 && line == 1)
					{
						obj.push_back(new Line);
						int indexLine = obj.size() - 1;

						obj[indexLine]->SetPoints(points[0], points[1], points[2], points[3]);
						obj[indexLine]->Draw();
						pcount = 0;
						select = 0;
						line = 0;
					}
					if (pcount == 2 && rectangle == 1)
					{
						obj.push_back(new RRectangle);
						int indexRect = obj.size() - 1;

						obj[indexRect]->SetPoints(points[0], points[1], points[2], points[3]);
						obj[indexRect]->Draw();
						pcount = 0;
						select = 0;
						rectangle = 0;
						rectangledrawn = 1;
					}
				
				}
			
			}

			

			if (contain == 1)
			{
				//GP142_printfXY(1, 0, 0, 15, "CONTAIN!!");

				if (circledrawn == 1)
				{

					if (obj[indexCircle]->contain(points[0], points[1]) == true)
						GP142_printfXY(1,  mouse_x, mouse_y, 10, "Inside");
					else if(obj[indexCircle]->contain(points[0], points[1]) == false)
						GP142_printfXY(1, mouse_x, mouse_y, 10, "Outside");
				}
			}

			if (FILL == 1)
			{
				if (circledrawn == 1)
				{

					if (obj[indexCircle]->contain(mouse_x, mouse_y) == TRUE)
					{
						obj[indexCircle]->fillColor(bucket);
					}
					else if (obj[indexCircle]->contain(mouse_x, mouse_y) == FALSE)
					{
						//do nothing
					}
				}
				if (rectangledrawn == 1)
				{
					if (obj[indexRect]->contain(mouse_x, mouse_y) == TRUE)
					{
						obj[indexRect]->fillColor(bucket);
					}
					else if (obj[indexRect]->contain(mouse_x, mouse_y) == FALSE)
					{
						//do nothing
					}
				}
				

				FILL = 0;
				bucket = 0;
				select = 0;

			}

			demo_handle_mouse(mouse_x, mouse_y);
			break;


		case GP142_MOUSER:
			if (polygon == 1)
			{
				
				PolygonPoints[2 * PPcount] = mouse_x;
				PolygonPoints[2 * PPcount + 1] = mouse_y;
				PPcount++;


				obj.push_back(new PPolygon(1, PPcount));
				int indexPoly = obj.size() - 1;


				while (c1 < PPcount)
				{
					if (PolygonPoints[ip] != 1000 && PolygonPoints[ip + 1] != 1000 )
					{
						obj[indexPoly]->SetPoints(PolygonPoints[ip], PolygonPoints[ip + 1], 0, 0);
					}
					ip = ip + 2;
					c1++;
				}
				obj[indexPoly]->Draw();
				PPcount = 0;
				polygon = 0;
				select = 0;
			}
			else if (curve == 1)
			{
				CurvePoints[2 * CPcount] = mouse_x;
				CurvePoints[2 * CPcount + 1] = mouse_y;
				CPcount++;

				obj.push_back(new Curve(CPcount));
				int indexCurve = obj.size() - 1;

				while (c2 < CPcount)
				{
					if (CurvePoints[ic] != 1000 && CurvePoints[ic + 1] != 1000)
					{
						obj[indexCurve]->SetPoints(CurvePoints[ic], CurvePoints[ic + 1], 0, 0);
					}
					ic = ic + 2;
					c2++;
				}

				obj[indexCurve]->Draw();
				CPcount = 0;
				curve = 0;
				select = 0;
			}
		
			break;

		case GP142_KBD:
			//Keyboard handler
			demo_handle_kbd(key_pressed);
			if (text == 1)
			{
				arr[1]->SetPoints(points[key], points[key], 0, 0);
				arr[1]->drawtext(key_pressed);
				key++;
				text = 0;
				select = 0;
				pcount = 0;
				
			}
			break;

		case GP142_PERIODIC:
			//timer handler
			//demo_handle_periodic();
			break;
		default:
			break;
		}
	}


		GP142_close();          /* Clean up and close graphics window           */

		return 0;
}
