#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "character.h"

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1080

void game();

enum Layer
{
	TOP,
	MIDDLE,
	BOTTOM
};


#endif