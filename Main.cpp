#include <iostream>
#include <string>

#include <cstdio>
#include <stdlib.h> /* srand, rand */
#include "Clock.h"

#include <graphics.h>
#include "Shape.hpp"
#include "Circle.hpp"
#include "Square.hpp"

#include "GameManager.hpp"

using namespace std;

int main() 
{ 
	bool gameover = false;
	while(gameover == false)
	{
		int gamemode = 0;
		char ch2 = 0;
		bool game = false;
		while(game != true)
		{
			int starting_choice = startingMenu(gameover);
			// cout << starting_choice;
			if (starting_choice == 1) 
			{	
				gamemode = difficultyMenu();
				// 	if(gamemode != 3)
				// 		break ;
				// 	startingMenu(gameover) ;

				// }while(gamemode == 3);
				if(gamemode == 1 || gamemode == 2)
					game = true;
			}
			else if (starting_choice == 2)
			{
				howtoplayMenu();
			}
			else
			{	
				exit(1);
			}
		}
		
		Clock<> clock;
		long long rate = 2000;
		int max_rate = 600;

		int lifepoint = 10 + 1;
		int hit = 0, miss = 0, out = -1;
		
		int width = getmaxwidth();
		int height = getmaxheight();
		int playheight = height / 8 * 6;
		char ch = 0; // Set placeholder key
		int radius = 100;
		
		int score = 0;
		int score_temp = 0;
		int combo = 0;
		int max_combo = 0;
		// To initialize WinBGI and open a new window for graphic display
		initwindow(width, height, "Click & Go");

		/* initialize random seed: */
		srand(time(NULL));

		readimagefile("asset/game_background.jpg", 0, 0, width, height);
		
		Shape *p [2] ;
		Circle circles;
		Square squares;
		p[0] = &circles ;
		p[1] = &squares ;

		



		// For Hard Gamemode
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
					if (combo >= max_combo)
					{
						max_combo = combo;
					}				
					//cout << "max COMBO: " << max_combo << endl; 
					clock.reset();
					drawing(p, circles, squares, width, playheight, 2, "HIT");
					hit++;
					setcolor(WHITE);
					points(width, height, lifepoint, score, combo, max_combo, hit, miss, out);

					// RATE decrease (Gives player less time to react as the score gets higher) 
					if (rate > max_rate) 
					{
						if(score - 10000 >= score_temp)
						{
							rate -= 200;
							score_temp += 10000;
							// cout << "rate decreased " << rate << endl;
						}
					}
				}
				else 
				{	
					lifepoint--;
					combo = 0;
					clock.reset();
					drawing(p, circles, squares, width, playheight, 15, "MISS");
					miss++;
					points(width, height, lifepoint, score, combo, max_combo, hit, miss, out);
				}
			}

			else if (clock.getMilliseconds() == rate)
			{
				lifepoint--;
				combo = 0 ;
				clock.reset();
				drawing(p, circles, squares, width, playheight, 15, "OUT");
				out++;
				points(width, height, lifepoint, score, combo, max_combo, hit, miss, out);
			}
						
			if (lifepoint == 0)
			{
				cout << "Game Over" << endl;	
				// gameover = true;
				gameover = gameOver(score, max_combo, hit, miss, out);

				if(gameover == true)
					exit(1);
				else
					break;
			}
		}
	}
  	return 0 ;
}	
