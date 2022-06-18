#include <iostream>
#include <string>
#include <graphics.h>
#include <cstdio>
#include <stdlib.h> /* srand, rand */
#include "Clock.h"
#include "Shape.hpp"
#include <stdio.h>
#include <conio.h>

using namespace std;

int displacement(const Circle &c1, const Circle &c2);
int randomGenerator(int offset, int max);

void DisplayText(char* const text)
{
	int gdriver = DETECT, gmode, errorcode;

	int style, midx, midy;

	int size = 1 ;
	/* initialize graphics and local variables */

	initgraph(&gdriver, &gmode, "");

	/* read result of initialization */

	errorcode = graphresult();

	if (errorcode != grOk) {  /* an error occurred */

		printf("Graphics error: %s\n", grapherrormsg(errorcode));

		printf("Press any key to halt:");

		getch();

		exit(1);               /* terminate with an error code */
	}

	midx = getmaxx() / 2;

	midy = getmaxy() / 2;
	style = 6 ;
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	cleardevice();

	settextstyle(style, HORIZ_DIR, size);
	outtextxy(midx, midy, text);

	if(getch()){
		closegraph();
		return ;
	}


	/* clean up */
}

int main() 
{ 
	DisplayText("PRESS ANY KEY TO START THE GAME") ;
	Clock<> clock;
	constexpr long long spawnRate= 1;
    constexpr long long Rate = 2;
    int Lifepoint = 10 ;
    int width = getmaxwidth();
    int height = getmaxheight();
    char ch = 0; // Set placeholder key
    // const int count = 2;
    int radius = 100;
    int w_Max, h_Max;

    // To initialize WinBGI and open a new window for graphic display
    initwindow(width, height, "Click & Go");

    /* initialize random seed: */
    srand(time(NULL));

    Circle circles;
	// w_Max = randomGenerator(radius, width);
	// h_Max = randomGenerator(radius, height);
	circles.setLocation(w_Max, h_Max);
	circles.setRadius(radius);

	//Game Loop
    while (ch != 27) // ASCII code 27 is the ESC key
    {
      	//Global Clock
        //cout << clock.getSeconds() << endl;
        if (clock.getSeconds() == spawnRate) 
        {
			w_Max = randomGenerator(radius, width);
			h_Max = randomGenerator(radius, height);
			circles.setLocation(w_Max, h_Max);
			circles.draw();
			// clock.reset();
        }

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int mx, my;
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			// cout << mx << endl;
			Circle cur = Circle(mx, my, 0);


			if (displacement(circles, cur) <= radius)
			{
				cout << "Hit" << endl;
				circles.undraw();
				clock.reset();
			}
			else 
			{
				circles.undraw();
				Lifepoint--;
				cout << "Miss" << endl;
				clock.reset();
			}

		}

		if(clock.getSeconds() == Rate)
		{
			Lifepoint--;
			cout << "Out of Bound" << endl;
			circles.undraw();
			clock.reset();
		}
					
		if (Lifepoint == 0)
		{
			DisplayText("GAME OVER");
			cout << "Game Over" << endl;
			exit(1);
		}
		// clock.reset();
		delay(1000);  
	}
  	return 0 ;
}	
    
//Functions

int displacement(const Circle &c1, const Circle &c2)
{
	Circle c = c1;
	return c - c2;
}

int randomGenerator(int offset, int max) 
{
	int pos = rand() % (max - offset);
	if(pos <= offset)
		return pos + offset;
	return pos;
}