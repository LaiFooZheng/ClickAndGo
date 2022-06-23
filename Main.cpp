#include <iostream>
#include <string>

#include <cstdio>
#include <stdlib.h> /* srand, rand */
#include "Clock.h"

#include <graphics.h>
#include "Shape.hpp"

#include <stdio.h>
#include <conio.h>
#include "Utility.hpp"

using namespace std;

void Drawing(Circle &circles, int width , int height, int color)
{
	circles.undrawCircle();
	circles.setLocationCircle(width, height);
	circles.drawCircle(color);
}

void Points(int width, int lifepoint, int score){
	char msg[128];
	char msg2[128];

	cleartext(0, 0);
	cleartext(width - 300, 0);
	sprintf(msg, "Life :%d", lifepoint);
	sprintf(msg2, "Score :%d", score);
	settextstyle(2, 0, 10);
	outtextxy(0, 0, msg);
	outtextxy(width - 300, 0, msg2);
}

int displacement(const Circle &c1, const Circle &c2){
	Circle c = c1;
	return c - c2;
}




int main() 
{ 
	DisplayText("PRESS ANY KEY TO START THE GAME") ;
	Clock<> clock;
	// constexpr long long spawnRate= 1;
    constexpr long long Rate = 1000;
    int lifepoint = 10 ;
    int width = getmaxwidth();
    int height = getmaxheight();
    char ch = 0; // Set placeholder key
    // const int count = 2;
    int radius = 100;
    int w_Max, h_Max;
	int style = 4;
	int size = 1;
	int score = 0;

    // To initialize WinBGI and open a new window for graphic display
    initwindow(width, height, "Click & Go");

    /* initialize random seed: */
    srand(time(NULL));
	readimagefile("Click & GO Storyboard.jpg", 0 , 0, width , height);

    Circle circles;
	circles.setLocationCircle(width, height);
	circles.setRadius(radius);
	circles.drawCircle(15); // White

	//Game Loop
    while (ch != 27) // ASCII code 27 is the ESC key
    {
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int mx, my;
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			Circle cur = Circle(mx, my, 0);

			if (displacement(circles, cur) <= radius)
			{
				score += 100;
				clock.reset();
				Drawing(circles, width, height, 2);
				setcolor(WHITE);
				Points(width, lifepoint, score) ;
			}
			else 
			{
				lifepoint--;
				clock.reset();
				Drawing(circles, width, height, 15);
				Points(width, lifepoint, score) ;
			}
		}

		else if (clock.getMilliseconds() == Rate)
		{
			lifepoint--;
			clock.reset();
			Drawing(circles, width, height, 15);
			Points(width, lifepoint, score) ;
		}
					
		if (lifepoint == 0)
		{
			DisplayText("GAME OVER");
			cout << "Game Over" << endl;
			exit(1);
		}
		// clock.reset();
		// delay(1000);  
	}
  	return 0 ;
}	
