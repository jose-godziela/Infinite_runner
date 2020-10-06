#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "game.h"
#include <iostream>



class Character {
private:
	Rectangle _rec;
	Vector2 _pos;
	int _mov_key_UP;
	int _mov_key_DOWN;
	int _mov_key_left;
	int _mov_key_right;
	int _jump_key;
	int _lives;
	int _score;
	//Layer _layer;
public:
	
	Character();//
	~Character();//
	void set_pos(Vector2 pos);//
	void set_jump_key(int jump_key);//
	void set_mov_key_UP(int mov_key_UP);//
	void set_mov_key_DOWN(int mov_key_DOWN);//
	void set_mov_key_LEFT(int mov_key_LEFT);
	void set_mov_key_RIGHT(int mov_key_RIGHT);
	void set_rec(Rectangle rec);
	//void set_layer(Layer layer);
	Vector2 get_pos();//
	int get_mov_key_UP();
	int get_mov_key_DOWN();
	int get_mov_key_LEFT();
	int get_mov_key_RIGHT();

	int get_jump_key();
	Rectangle get_rec();
	//Layer get_layer();
};


#endif