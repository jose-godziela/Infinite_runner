#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include <iostream>

class Character {
private:
	Rectangle _rec;
	Vector2 _pos;
	int _mov_key_UP;
	int _mov_key_DOWN;
	int _jump_key;
	int _lives;
	int _score;
public:
	Character();//
	~Character();//
	void set_pos(Vector2 pos);//
	void set_jump_key(int jump_key);//
	void set_mov_key_UP(int mov_key_UP);//
	void set_mov_key_DOWN(int mov_key_DOWN);//
	void set_rec(Rectangle rec);
	void move_L();
	void move_R();
	Vector2 get_pos();//
	int get_mov_key_UP();
	int get_mov_key_DOWN();
	int get_jump_key();
	Rectangle get_rec();
};


#endif