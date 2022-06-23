#include <iostream>
#include <string>

#include <cstdio>
#include <stdlib.h> /* srand, rand */
#include "Clock.h"

#include <graphics.h>
#include "Shape.hpp"

#include "GameManager.hpp"

using namespace std;

int main() 
{ 
	DisplayText("PRESS ANY KEY TO START THE GAME");
	Clock<> clock;
    constexpr long long Rate = 1000;
    int lifepoint = 10 ;
    int width = getmaxwidth();
    int height = getmaxheight();
	int playheight = height / 8 * 6;
    char ch = 0; // Set placeholder key
    int radius = 100;
    
	int score = 0;

    // To initialize WinBGI and open a new window for graphic display
    initwindow(width, height, "Click & Go");

    /* initialize random seed: */
    srand(time(NULL));
	readimagefile("Click & GO Storyboard.jpg", 0 , 0, width , height);

    Circle circles;
	// circles.setLocationCircle(width, height);
	// circles.setRadius(radius);
	// circles.drawCircle(15); // White

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
				Drawing(circles, width, playheight, 2);
				setcolor(WHITE);
				Points(width, height, lifepoint, score);

				cout << "HIT" << endl;
			}
			else 
			{
				lifepoint--;
				clock.reset();
				Drawing(circles, width, playheight, 15);
				Points(width, height, lifepoint, score);
				cout << "MISS" << endl;
			}
		}

		else if (clock.getMilliseconds() == Rate)
		{
			lifepoint--;
			clock.reset();
			Drawing(circles, width, playheight, 15);
			Points(width, height, lifepoint, score) ;

			cout << "NO INPUT" << endl;
		}
					
		if (lifepoint == 0)
		{
			cout << "Game Over" << endl;
			cout << height << endl;
			cout << width << endl;
			DisplayText("GAME OVER");
			exit(1);
		}
	}
  	return 0 ;
}	
