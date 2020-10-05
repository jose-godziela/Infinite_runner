#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include <iostream>

class Character {
private:
	Rectangle _rec;
	Vector2 _pos;
	int _mov_key_L;
	int _mov_key_R;
	int _jump_key;
	int _lives;
	int _score;
public:
	Character();//
	~Character();//
	void set_pos(Vector2 pos);//
	void set_jump_key(int jump_key);//
	void set_mov_key_R(int mov_key_R);//
	void set_mov_key_L(int mov_key_L);//
	void set_rec(Rectangle rec);
	Vector2 get_pos();//
	int get_mov_key_L();
	int get_mov_key_R();
	int get_jump_key();
	Rectangle get_rec();
};


#endif