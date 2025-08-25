#include <stdio.h>
#include <raylib.h>
#include "Game.h"

const int HEIGHT = 600;
const int WIDTH = 800;
const int CELLSIZE = 8;

Vector2 mousePos;

int main(){

	gConfig gconf = {0};

	initGame(&gconf, WIDTH, HEIGHT, CELLSIZE);

	int FPS = 10;

	/*
	ON(&gconf, 50, 50);
	ON(&gconf, 51, 50);
	ON(&gconf, 51, 51);
	ON(&gconf, 50, 51);
	*/
	InitWindow(WIDTH, HEIGHT, "Game of life");
	ClearBackground(WHITE);
	SetTargetFPS(FPS);

	while (!WindowShouldClose())
	{
		mousePos = GetMousePosition();


		if(!gconf.gameStarted){
			DrawText("PAUSED", gconf.WIDTH - 100, 100, 10 ,BLACK);
			if (IsMouseButtonDown(0))
			{
				//puts("MORO");
				ON(&gconf, (int)mousePos.y / CELLSIZE, (int)mousePos.x / CELLSIZE);
			}
			else if (IsMouseButtonPressed(1))
			{
				OFF(&gconf, (int)mousePos.y / CELLSIZE, (int)mousePos.x / CELLSIZE);
			}
		}
		if(IsKeyPressed('P')){
			gconf.gameStarted = (gconf.gameStarted != 0 ? 0 : 1);
		}
		if(IsKeyPressed(KEY_UP)){
			FPS+=10;	
			SetTargetFPS(FPS);
		}
		if(IsKeyPressed(KEY_DOWN) && FPS > 11){
			FPS-=10;	
			SetTargetFPS(FPS);
		}

		updateGame(&gconf);
		BeginDrawing();

		ClearBackground(WHITE);

		drawGame(&gconf);

		EndDrawing();
	}

	closeGame(&gconf);

	return 0;
}
