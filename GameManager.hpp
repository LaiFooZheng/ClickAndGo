#pragma once

int startingMenu(bool gameover);

int howtoplayMenu();

int difficultyMenu();

void cleartext(int x, int y);

void points(int width, int height, int lifepoint, int score, int combo, int max_combo, int hit, int miss, int out);

bool gameOver(int score, int max_combo, int hit, int miss, int out);

void drawing(Shape **p, Circle &circles, Square &squares, int width, int playheight, int color ,char* text);