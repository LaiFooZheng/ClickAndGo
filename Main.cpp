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
	bool gameover = false;
	int gamemode = difficultyMenu(gameover);
	cout << gamemode << endl ;
	Clock<> clock;
    /*constexpr*/ long long Rate = 1000;
    int lifepoint = 10 + 1;
    int width = getmaxwidth();
    int height = getmaxheight();
	int playheight = height / 8 * 6;
    char ch = 0; // Set placeholder key
    int radius = 100;
    
	int score = 0;
	int combo = 0;
    // To initialize WinBGI and open a new window for graphic display
    initwindow(width, height, "Click & Go");

    /* initialize random seed: */
    srand(time(NULL));

	readimagefile("Click & GO Storyboard.jpg", 0 , 0, width , height);

    Circle circles;
		Square squares ;

		// Square enabler for hard mode
		if(gamemode == 2){
			squares.set_Side(100) ;
			// setcolor(WHITE) ;
			// squares.setLocationSquare(width, height) ;
			// squares.drawSquare() ;
		}

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
				score += ++combo * 100;
				cout << "COMBO: " << combo << endl; 
				clock.reset();
				drawing(circles, squares, width, playheight, 2, "HIT");
				setcolor(WHITE);
				points(width, height, lifepoint, score, combo);

				// RATE decreaser 
				if(score % 10000 == 0)
					Rate -= 100 ;

				cout << "HIT" << endl;
			}
			else 
			{	
				lifepoint--;
				combo = 0 ;
				clock.reset();
				drawing(circles, squares, width, playheight, 15, "MISS");
				points(width, height, lifepoint, score, combo);

				cout << "MISS" << endl;
			}
		}

		else if (clock.getMilliseconds() == Rate)
		{
			lifepoint--;
			combo = 0 ;
			clock.reset();
			drawing(circles, squares, width, playheight, 15, "OUT");
			points(width, height, lifepoint, score, combo);

			cout << "NO INPUT" << endl;
		}
					
		if (lifepoint == 0)
		{
			cout << "Game Over" << endl;	
			gameover = true;
			cout << height << endl;
			cout << width << endl;
			difficultyMenu(gameover);
			exit(1);
		}
	}

  	return 0 ;
}	