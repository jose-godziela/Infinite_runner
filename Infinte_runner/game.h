#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iterator>
#include <iostream>

#include "raylib.h"
#include "character.h"
#include "obstacle.h"

using namespace std;

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 1080
#define FPS 60
#define MIN_ENEMIES_GENERATED 1
#define MAX_ENEMIES_GENERATED 5
#define TAM_ENEMIES 200

void game();

struct Object_obstacle
{
	Obstacle obstacle;
	bool active;
};

#endif