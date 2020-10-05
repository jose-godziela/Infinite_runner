#include "game.h"
Rectangle aux_rec;

int main()
{
	Character* p = new Character();

	Vector2 aux_pos = { 50,50 };

	aux_rec.x = 50;
	aux_rec.y = 50;
	aux_rec.width = 20;
	aux_rec.height = 20;

	p->set_jump_key(KEY_SPACE);
	p->set_mov_key_L(KEY_LEFT);
	p->set_mov_key_R(KEY_RIGHT);
	p->set_pos(aux_pos);
	p->set_rec(aux_rec);

	std::cout << p->get_jump_key() << std::endl;
	std::cout << p->get_mov_key_L() << std::endl;
	std::cout << p->get_mov_key_R() << std::endl;


	delete p;

	return 0;
}