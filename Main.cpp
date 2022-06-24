#include <iostream>
#include <string>
#include <graphics.h>
#include <cstdio>
#include <stdlib.h> /* srand, rand */
#include "Clock.h"
#include "Circle.hpp"
#include <stdio.h>
#include <conio.h>
#include "Shape.hpp"
#include "Triangle.hpp"
using namespace std;

int displacement(const Circle &c1, const Circle &c2);
void Drawing( Circle&, int ,int, int);
void Points(int, int, int) ;
// void DisplayText(char* const text)
int DisplayText(bool gameover)
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


	int width = getmaxx() ;
	int height = getmaxy() ;
	style = 6 ;
	char ch = 0;
	cleardevice();

	
	if(gameover == false){
			readimagefile("Click & GO Storyboard (Difficulty).jpg", 0 , 0, width , height) ;
		while (ch != 27) {
			cout << mousex() << " " << mousey() << endl ;
			int mx = mousex() ;
			int my = mousey() ;
			if(mx > 200 && mx < 450 && my > 220 && my < 250  )
				readimagefile("Click & GO Storyboard (normal).jpg", 0 , 0, width , height) ;
			else if(mx > 245 && mx < 400 && my > 240 && my < 325)
				readimagefile("Click & GO Storyboard (hard).jpg", 0 , 0, width , height) ;
			else if(mx > 220 && mx < 430 && my > 370 && my < 400)
				readimagefile("Click & GO Storyboard (insane).jpg", 0 , 0, width , height) ;
			else
				readimagefile("Click & GO Storyboard (Difficulty).jpg", 0 , 0, width , height) ;

			if (ismouseclick(WM_LBUTTONDOWN)){
				
				int mx , my ;
				getmouseclick(WM_LBUTTONDOWN, mx, my);{
					cout << mx << "  " << my << endl ;
					if(mx > 200 && mx < 450 && my > 220 && my < 250  )
					return 1 ;
					else if(mx > 245 && mx < 400 && my > 240 && my < 325)
					return 2 ;
					else if(mx > 220 && mx < 430 && my > 370 && my < 400)
					return 3;
					
				}
			}
		}
	
	}
	else{
		
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		settextstyle(style, HORIZ_DIR, size);

		midx = getmaxx() / 2;
		midy = getmaxy() / 2;

	char* text = "GAME OVER" ;
	outtextxy(midx, midy, text);

	if(getch()){
		closegraph();
		return 0;
	}
	}
	/* clean up */
}

void cleartext(int x, int y)
{
  // setfillstyle(SOLID_FILL, getmaxcolor());
  setfillstyle(SOLID_FILL, 0);
  bar(x, y, 220, 40);
}

int main() 
{ 
	bool gameover = false ;
	// DisplayText("PRESS ANY KEY TO START THE GAME") ;
	cout << DisplayText(gameover) ;
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
	char msg[128];
	char msg2[128];
	int style = 4;
	int size = 1;
	int score = 0;

    // To initialize WinBGI and open a new window for graphic display
    initwindow(width, height, "Click & Go");

    /* initialize random seed: */
    srand(time(NULL));
	readimagefile("Click & GO Storyboard.jpg", 0 , 0, width , height);

  Circle circles;
	circles.setLocation(width, height);
	circles.setRadius(radius);
	circles.draw(15); // White

	Triangle triangles ;

	//Game Loop
    while (ch != 27) // ASCII code 27 is the ESC key
    {	

		
	if (ismouseclick(WM_LBUTTONDOWN))
		{
			int mx, my;
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			// cout << mx << endl;
			Circle cur = Circle(mx, my, 0);

			if (displacement(circles, cur) <= radius)
			{
				clock.reset();
				score += 100;
				triangles.setLocation(width, height) ;
				triangles.draw() ;
				Drawing(circles, width, height, 2);
				setcolor(WHITE);
				Points(width, lifepoint, score);
			}
			else 
			{
				clock.reset();
				circles.undraw();
				lifepoint--;
				cout << "Miss" << endl;
				circles.setLocation(width, height);
				circles.draw(15);
				Drawing(circles, width, height, 15);
				Points(width, lifepoint, score);
			}
		}

		else if (clock.getMilliseconds() == Rate)
		{
			lifepoint--;
			clock.reset();
			Drawing(circles, width, height, 15);
			Points(width, lifepoint, score);
		}
					
		if (lifepoint == 0)
		{
			// DisplayText("GAME OVER");
			gameover = true ;
			DisplayText(gameover);
			exit(1);
		}
		// clock.reset();
		// delay(1000);  
	}
  	return 0 ;
}	
    
//Functions

int displacement(const Circle &c1, const Circle &c2)
{
	Circle c = c1;
	return c - c2;
}

void Drawing(Circle &circles, int width , int height, int color){
		circles.undraw();
		circles.setLocation(width, height);
		circles.draw(color);
}

void Points(int width, int lifepoint, int score){
	char msg[128];
	// char *msg2 = new char[strlen(msg)] ;
	char msg2[128] ;
				cleartext(0, 0);
	cleartext(width - 300, 0);
	sprintf(msg, "Life :%d", lifepoint);
	sprintf(msg2, "Score :%d", score);
	settextstyle(2, 0, 10);
	outtextxy(0, 0, msg);
	outtextxy(width - 300, 0, msg2);

	// delete [] msg2 ;
}