#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void DisplayText(char* const text)
{
	int gdriver = DETECT, gmode, errorcode;

	int style = 6, midx, midy;
	
	int size = 1;
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

	settextjustify(CENTER_TEXT, CENTER_TEXT);
	cleardevice();

	settextstyle(style, HORIZ_DIR, size);
	outtextxy(midx, midy, text);

	if(getch())
    {
		closegraph();
		return;
	}
}

void cleartext(int x, int y)
{
	setfillstyle(SOLID_FILL, 0);
	bar(x, y, 220, 40);
}
