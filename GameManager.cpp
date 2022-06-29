#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "Shape1.hpp"

int difficultyMenu(bool gameover)
{
	int gdriver = DETECT, gmode, errorcode;
	int style = 6, midx, midy;
	int size = 1 ;
	/* initialize graphics and local variables */

	initgraph(&gdriver, &gmode, "");

	/* read result of initialization */

	errorcode = graphresult();
	if (errorcode != grOk) 
	{  /* an error occurred */
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);               /* terminate with an error code */
	}

	int width = getmaxx() ;
	int height = getmaxy() ;
	char ch = 0;
	cleardevice();

	if(gameover == false) 
	{
		readimagefile("Click & GO Storyboard (Difficulty).jpg", 0 , 0, width , height);
		while (ch != 27) 
		{
			// std::cout << mousex() << " " << mousey() << std::endl ;
			int mx = mousex() ;
			int my = mousey() ;
			if(mx > 200 && mx < 450 && my > 220 && my < 250)
				readimagefile("Click & GO Storyboard (normal).jpg", 0 , 0, width , height);
			else if(mx > 245 && mx < 400 && my > 294 && my < 325)
				readimagefile("Click & GO Storyboard (hard).jpg", 0 , 0, width , height);
			else if(mx > 220 && mx < 430 && my > 370 && my < 400)
				readimagefile("Click & GO Storyboard (insane).jpg", 0 , 0, width , height);
			else
				readimagefile("Click & GO Storyboard (Difficulty).jpg", 0 , 0, width , height);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				int mx , my ;
				getmouseclick(WM_LBUTTONDOWN, mx, my);
				std::cout << mx << "  " << my << std::endl;
				if(mx > 200 && mx < 450 && my > 220 && my < 250){
					closegraph();
					return 1 ;
				}
				else if(mx > 245 && mx < 400 && my > 294 && my < 325){
					closegraph();
					return 2 ;
				}
				else if(mx > 220 && mx < 430 && my > 370 && my < 400){
					closegraph();
					return 3;
				}
				
			}
		}
	}
	else 
	{
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		settextstyle(style, HORIZ_DIR, size);

		midx = getmaxx() / 2;
		midy = getmaxy() / 2;

		char* text = "GAME OVER" ; // Do a game over menu later
		outtextxy(midx, midy, text);

		if(getch())
		{
			closegraph();
			return 0;
		}
	}
	/* clean up */
}

void cleartext(int x1, int y1, int x2, int y2)
{
	setfillstyle(SOLID_FILL, 0);
	bar(x1, y1, x2, y2);
}

void points(int width, int height, int lifepoint, int score, int combo)
{
	int width_offset = width / 16;
	int height_offset = height / 36;

	char msg[128];
	char msg2[128];
	char msg3[128];

	cleartext(width_offset / 2, 0, width_offset * 2, height_offset * 3);
	cleartext(width - (width_offset * 3), 0, width, height_offset * 3);
	cleartext(width_offset / 2, height_offset * 34, width_offset * 4, height);

	sprintf(msg, "Life: %d", lifepoint);
	sprintf(msg2, "Score: %d", score);
	sprintf(msg3, "Combo: %d X", combo);

	settextstyle(2, 0, 10);

	outtextxy(width_offset / 2, height_offset , msg);
	outtextxy(width - (width_offset * 3), height_offset, msg2);
	outtextxy(width_offset / 2, height_offset * 34, msg3);
}

void displayText(const Circle &circles, char *text) 
{
	int x = circles.m_x;
	int y = circles.m_y;
	int r = circles.m_r;

	settextstyle(2, 0, 8);
	setcolor(WHITE) ;
	outtextxy(x - r / 3, y - r / 6, text);
	delay(200);
	cleartext(x - r / 3, y - r / 6 , x + r / 2, y + r / 2);
}