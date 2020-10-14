#include "game.h"

Vector2 aux_pos;
Rectangle aux_rec;
Character* p = new Character();
void draw_lanes(int lane_counter, int lane_height, Color* colors);
void init_lines(int lanes_height, Color* colors);
void generate_enemy(int random_generator, Object_obstacle* arr_obs);
void init();
//aux
int random_generator, random_time;
int lane_counter = 16;
int lane_height = 50;
int indice = 0;
int timer = 0;
bool window_closed;

void game()
{

	float time_generation = 2 * FPS;
	window_closed = false;

	init();

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TEST");

	Color* colors = new Color[lane_counter];
	Object_obstacle* arr_obs = new Object_obstacle[TAM_ENEMIES];

	SetTargetFPS(FPS);

	init_lines(lane_counter, colors);

	random_time = GetRandomValue(0, time_generation);

	init();

	while (!WindowShouldClose() && !window_closed)
	{
		//draw
		BeginDrawing();
		ClearBackground(BLACK);

		if (p->get_alive())
		{

			draw_lanes(lane_counter, lane_height, colors);
			DrawRectangleRec(p->get_rec(), BLACK);

			//update

			if (random_time <= 0)
			{
				random_time = GetRandomValue(0, time_generation);
				random_generator = GetRandomValue(MIN_ENEMIES_GENERATED, MAX_NORMAL_ENEMIES_GENERATED);
				generate_enemy(random_generator, arr_obs);
			}
			random_time--;

			for (int i = 0; i < TAM_ENEMIES; i++)
			{
				if (arr_obs[i].active)
				{
					arr_obs[i].obstacle.update();
					DrawRectangleRec(arr_obs[i].obstacle.get_rec(), arr_obs[i].obstacle.get_color());
					if (arr_obs[i].obstacle.get_rec().x < 0)
					{
						arr_obs[i].active = false;
					}
				}
			}


			//input
			if (p->get_alive())
			{
				if (IsKeyPressed(p->get_mov_key_UP()))
				{
					std::cout << "Me muevo para arriba" << std::endl;
					aux_pos.y -= 50;
					p->set_pos(aux_pos);
				}
				if (IsKeyPressed(p->get_mov_key_DOWN()))
				{
					std::cout << "Me muevo para abajo" << std::endl;
					aux_pos.y += 50;
					p->set_pos(aux_pos);
				}

				if (IsKeyPressed(p->get_mov_key_LEFT()))
				{
					std::cout << "Me muevo para la izq" << std::endl;
					aux_pos.x -= 50;
					p->set_pos(aux_pos);
				}
				if (IsKeyPressed(p->get_mov_key_RIGHT()))
				{
					std::cout << "Me muevo para der" << std::endl;
					aux_pos.x += 50;
					p->set_pos(aux_pos);
				}
				p->set_score(p->get_score() + 1);
			}
			for (int i = 0; i < TAM_ENEMIES; i++)
			{
				if (CheckCollisionRecs(p->get_rec(), arr_obs[i].obstacle.get_rec()))
				{
					p->set_lives(p->get_lives() - 1);

				}
			}

			if (p->get_lives() <= 0)
			{
				p->set_alive(false);
			}

		}
		else
		{
			ClearBackground(BLACK);
			DrawText("GAME OVER", GetScreenWidth() / 2 - 20, GetScreenHeight() / 2, 20, RED);
			std::cout << p->get_score() << std::endl;
			timer++;
			if (timer >= 180)
			{
				window_closed = true;
			}
		}
		EndDrawing();

	}
	delete[] arr_obs;
	delete p;
	delete[] colors;
}

void draw_lanes(int lane_counter, int lane_height, Color* colors)
{
	for (int i = 0; i < lane_counter; i++)
	{
		DrawRectangle(0, i * lane_height, GetScreenWidth(), lane_height, colors[i]);
	}

}

void init_lines(int lane_counter, Color* colors)
{
	for (int i = 0; i < lane_counter; i++)
	{
		colors[i].a = 255;
		colors[i].r = GetRandomValue(0, 255);
		colors[i].g = GetRandomValue(0, 255);
		colors[i].b = GetRandomValue(0, 255);
		if (i > 0)
		{
			//to avoid having the same colors
			while (colors[i].r == colors[i - 1].r
				&& colors[i].g == colors[i - 1].g
				&& colors[i].b == colors[i - 1].b)
			{
				colors[i].r = GetRandomValue(0, 255);
				colors[i].g = GetRandomValue(0, 255);
				colors[i].b = GetRandomValue(0, 255);
			}
		}
	}
}

void generate_enemy(int random_generator, Object_obstacle* arr_obs)
{
	int agile_enemies = GetRandomValue(0, random_generator);
	Rectangle rec;
	std::cout << "GENERO: " << random_generator << endl;
	for (int i = 0; i < random_generator; i++)
	{
		Obstacle obs = Obstacle();
		rec.width = 10;
		rec.height = 10;
		rec.y = (GetRandomValue(0, lane_counter) * lane_height) - 30;
		rec.x = GetScreenWidth() + rec.width;
		obs.set_rec(rec);
		obs.set_color(WHITE);
		//list_obs.push_back(obs);
		for (int j = 0; j < TAM_ENEMIES; j++)
		{
			if (!arr_obs[j].active)
			{
				arr_obs[j].obstacle = obs;
				arr_obs[j].obstacle.set_speed(obs.get_speed());
				arr_obs[j].active = true;
				j = TAM_ENEMIES;
			}

		}
	}
	for (int i = 0; i < agile_enemies; i++)
	{
		short speed = 15;
		Agile_obs obs = Agile_obs();
		rec.width = 10;
		rec.height = 10;
		rec.y = (GetRandomValue(0, lane_counter) * lane_height) - 30;
		rec.x = GetScreenWidth() + rec.width;
		obs.set_rec(rec);
		obs.set_speed(speed);
		obs.set_color(RAYWHITE);
		//list_obs.push_back(obs);
		for (int j = 0; j < TAM_ENEMIES; j++)
		{
			if (!arr_obs[j].active)
			{
				arr_obs[j].obstacle = obs;
				arr_obs[j].active = true;
				j = TAM_ENEMIES;
			}

		}
	}
}

void init()
{
	aux_rec.x = 50;
	aux_rec.y = 50;
	aux_rec.width = 20;
	aux_rec.height = 20;
	aux_pos.x = SCREEN_WIDTH / 2;
	aux_pos.y = (SCREEN_HEIGHT / 2) + (aux_rec.width / 2) + 5;

	p->set_jump_key(KEY_SPACE);
	p->set_mov_key_UP(KEY_UP);
	p->set_mov_key_DOWN(KEY_DOWN);
	p->set_mov_key_LEFT(KEY_LEFT);
	p->set_mov_key_RIGHT(KEY_RIGHT);
	p->set_rec(aux_rec);
	p->set_pos(aux_pos);
}