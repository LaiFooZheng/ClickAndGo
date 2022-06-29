#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "Shape.hpp"

#include <iostream>

using namespace std ;

int startingMenu(bool gameover)
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
		readimagefile("asset/starting_menu", 0, 0, width , height);
		while (ch != 27) 
		{
			int mx = mousex() ;
			int my = mousey() ;
			if(mx > 241 && mx < 395 && my > 200 && my < 230)
				readimagefile("asset/starting_menu (play).jpg", 0 , 0, width , height);
			else if(mx > 115 && mx < 523 && my > 280 && my < 309)
				readimagefile("asset/starting_menu (howtoplay).jpg", 0 , 0, width , height);
			else if(mx > 255 && mx < 382 && my > 367 && my < 397)
				readimagefile("asset/starting_menu (exit).jpg", 0 , 0, width , height);
			else
				readimagefile("asset/starting_menu.jpg", 0 , 0, width , height);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				int mx , my ;
				getmouseclick(WM_LBUTTONDOWN, mx, my);
				std::cout << mx << "  " << my << std::endl;
				if(mx > 241 && mx < 395 && my > 200 && my < 230){
					closegraph();
					return 1 ;
				}
				else if(mx > 115 && mx < 523 && my > 280 && my < 309){
					closegraph() ;
					return 2 ;
				}
				else if(mx > 255 && mx < 382 && my > 367 && my < 397){
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
int howtoplayMenu()
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
	char ch = 0  ;
	cleardevice();
		while (ch != 27) 
	{
		readimagefile("asset/howtoplay.jpg", 0 , 0, width , height);

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int mx , my ;
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			std::cout << mx << "  " << my << std::endl;
			 if(mx > 535 && mx < 609 && my > 398 && my < 456){
				closegraph();
				return 2 ;
			}		
		}
	}
}

int difficultyMenu()
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

	readimagefile("asset/difficulty_menu", 0, 0, width , height);
	while (ch != 27) 
	{
		int mx = mousex() ;
		int my = mousey() ;
		if(mx > 200 && mx < 440 && my > 230 && my < 260)
			readimagefile("asset/difficulty_menu (normal).jpg", 0 , 0, width , height);
		else if(mx > 240 && mx < 400 && my > 313 && my < 341)
			readimagefile("asset/difficulty_menu (hard).jpg", 0 , 0, width , height);
		else
			readimagefile("asset/difficulty_menu.jpg", 0 , 0, width , height);

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int mx , my ;
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			std::cout << mx << "  " << my << std::endl;
			if(mx > 200 && mx < 440 && my > 230 && my < 260){
				closegraph();
				return 1 ;
			}
			else if(mx > 240 && mx < 400 && my > 313 && my < 341){
				closegraph();
				return 2 ;
			}	
			else if(mx > 535 && mx < 609 && my > 398 && my < 456){
				closegraph();
				return 3 ;
			}		
		}
	}
}

void cleartext(int x1, int y1, int x2, int y2)
{
	setfillstyle(SOLID_FILL, 0);
	bar(x1, y1, x2, y2);
}

void points(int width, int height, int lifepoint, int score, int combo, int max_combo, int hit, int miss, int out)
{
	int width_offset = width / 16;
	int height_offset = height / 36;

	char msg[128];
	char msg2[128];
	char msg3[128];
	char msg4[128];
	char msg5[128];
	char msg6[128];

	cleartext(width_offset / 2, 0, width_offset * 2, height_offset * 3);
	cleartext(width - (width_offset * 3), 0, width, height_offset * 3);
	cleartext(width_offset / 2, height_offset * 34, width_offset * 6, height);

	cleartext(width - (width_offset * 6), height_offset * 34, width, height);

	sprintf(msg, "Life: %d", lifepoint);
	sprintf(msg2, "Score: %d", score);
	sprintf(msg3, "Combo: %dX (MAX %dX)", combo, max_combo);
	sprintf(msg4, "Hit: %d", hit);
	sprintf(msg5, "Miss: %d", miss);
	sprintf(msg6, "Out: %d", out);

	settextstyle(2, 0, 10);
	outtextxy(width_offset / 2, height_offset, msg);
	outtextxy(width - (width_offset * 3), height_offset, msg2);
	outtextxy(width_offset / 2, height_offset * 34, msg3);

	settextstyle(2, 0, 9);
	outtextxy(width - (width_offset * 6), height_offset * 34, msg4);
	outtextxy(width - (width_offset * 4), height_offset * 34, msg5);
	outtextxy(width - (width_offset * 2), height_offset * 34, msg6);
}

void displayText(const Circle &circles, char *text) 
{
	int x = circles.m_x;
	int y = circles.m_y;
	int r = circles.m_r;

	settextstyle(2, 0, 8);
	setcolor(WHITE);
	outtextxy(x - r / 3, y - r / 6, text);
	delay(200);
	cleartext(x - r / 3, y - r / 6 , x + r / 2, y + r / 2);
}


bool Gameover(int score, int max_combo, int hit, int miss, int out)
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
	char ch = 0  ;

	cleardevice();
		readimagefile("asset/gameover_menu.jpg", 0 , 0, width , height);

	//text 
	char msg[128];
	char msg2[128];
	char msg3[128];
	char msg4[128];
	char msg5[128];

	sprintf(msg, "%d", score);
	sprintf(msg2, "%d", max_combo);
	sprintf(msg3, "%d", hit);
	sprintf(msg4, "%d", miss);
	sprintf(msg5, "%d", out);

	settextjustify(CENTER_TEXT, CENTER_TEXT);
	cout << score ;

		while (ch != 27) 
	{	

		settextstyle(2, 0 , 10);
		outtextxy(185, 265, msg);
		outtextxy(425, 265, msg2);
		settextstyle(2, 0 , 9);
		outtextxy(135, 356, msg3);
		outtextxy(493, 356, msg4);
		outtextxy(319, 356, msg5);


		int mx = mousex() ;
		int my = mousey() ;
		if(mx > 79 && mx < 276 && my > 401 && my < 440)
			readimagefile("asset/gameover_menu (backtomainmenu).jpg", 0 , 0, width , height);
		else if(mx > 465 && mx < 541 && my > 406 && my < 422)
			readimagefile("asset/gameover_menu (exit).jpg", 0 , 0, width , height);
		else 
			readimagefile("asset/gameover_menu.jpg", 0 , 0, width , height);

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int mx , my ;
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			std::cout << mx << "  " << my << std::endl;

			if(mx > 79 && mx < 276 && my > 401 && my < 440){
				closegraph();
				return false ;
			}
			else if(mx > 465 && mx < 541 && my > 406 && my < 422){
				return true ;
			}		
		}
	}

}