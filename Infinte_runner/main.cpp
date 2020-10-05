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
	p->set_mov_key_UP(KEY_UP);
	p->set_mov_key_DOWN(KEY_DOWN);
	p->set_pos(aux_pos);
	p->set_rec(aux_rec);


	InitWindow(1080,720, "TEST");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		//draw
		DrawRectangleRec(p->get_rec(),RED);
		
		//update
		if (IsKeyPressed(p->get_mov_key_UP()))
		{
			std::cout << "Me muevo para arriba" << std::endl;
		}
		if (IsKeyPressed(p->get_mov_key_DOWN()))
		{
			std::cout << "Me muevo para abajo" << std::endl;
		}
			

		EndDrawing();
	}


	delete p;

	return 0;
}