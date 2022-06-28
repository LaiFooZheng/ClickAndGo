#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int DisplayText(bool gameover)
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
			if(mx > 200 && mx < 450 && my > 220 && my < 250  )
				readimagefile("Click & GO Storyboard (normal).jpg", 0 , 0, width , height);
			else if(mx > 245 && mx < 400 && my > 240 && my < 325)
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
				if(mx > 200 && mx < 450 && my > 220 && my < 250)
					return 1 ;
				else if(mx > 245 && mx < 400 && my > 240 && my < 325)
					return 2 ;
				else if(mx > 220 && mx < 430 && my > 370 && my < 400)
					return 3;
				
			}
		}
	
	}
	else 
	{
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		settextstyle(style, HORIZ_DIR, size);

		midx = getmaxx() / 2;
		midy = getmaxy() / 2;

		char* text = "GAME OVER" ;
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

void Points(int width, int height, int lifepoint, int score)
{
	int width_offset = width / 16 * 3;
	int height_offset = height / 36;

	char msg[128];
	char msg2[128];

	cleartext(width_offset / 2, 0, width_offset * 2, height_offset * 3);
	cleartext(width - width_offset, 0, width, height_offset * 3);

	sprintf(msg, "Life: %d", lifepoint);
	sprintf(msg2, "Score: %d", score);
	settextstyle(2, 0, 10);

	outtextxy(width_offset / 2, height_offset , msg);
	outtextxy(width - width_offset, height_offset, msg2);
}

// void Choice(int choice){

// 	if(choice  = 1){
// 		TridrawTriangle() ;
// 	}
// }