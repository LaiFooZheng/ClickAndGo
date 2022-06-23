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
