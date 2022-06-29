#pragma once

int startingMenu(bool gameover);

int howtoplayMenu();

int difficultyMenu();

void cleartext(int x, int y);

void points(int width, int height, int lifepoint, int score, int combo, int max_combo, int hit, int miss, int out);

bool Gameover(int, int, int, int, int) ;