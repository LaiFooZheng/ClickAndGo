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

	Clock<> clock;
    long long rate = 2000;
	int max_rate = 600;
    int lifepoint = 10 + 1;
	
    int width = getmaxwidth();
    int height = getmaxheight();
	int playheight = height / 8 * 6;
    char ch = 0; // Set placeholder key
    int radius = 100;
    
	int score = 0;
	int score_temp = 0;
	int combo = 0;
    // To initialize WinBGI and open a new window for graphic display
    initwindow(width, height, "Click & Go");

    /* initialize random seed: */
    srand(time(NULL));

	readimagefile("Click & GO Storyboard.jpg", 0 , 0, width , height);

    Circle circles;
	Square squares;

	if(gamemode == 2)
	{
		squares.setSide(100);
			
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
				// cout << "COMBO: " << combo << endl; 
				clock.reset();

				drawing(circles, squares, width, playheight, 2, "HIT");
				setcolor(WHITE);
				points(width, height, lifepoint, score, combo);

				// RATE decreaser 
				if (rate > max_rate) 
				{
					if(score - 10000 >= score_temp)
					{
						rate -= 200;
						score_temp += 10000;
						cout << "rate decreased " << rate << endl;
					}
				}
			}
			else 
			{	
				lifepoint--;
				combo = 0 ;
				clock.reset();

				drawing(circles, squares, width, playheight, 15, "MISS");
				points(width, height, lifepoint, score, combo);
			}
		}

		else if (clock.getMilliseconds() == rate)
		{
			lifepoint--;
			combo = 0 ;
			clock.reset();

			drawing(circles, squares, width, playheight, 15, "OUT");
			points(width, height, lifepoint, score, combo);
		}
					
		if (lifepoint == 0)
		{
			cout << "Game Over" << endl;	
			gameover = true;
			difficultyMenu(gameover);
			exit(1);
		}
	}

  	return 0 ;
}	
