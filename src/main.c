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

	/*
	ON(&gconf, 50, 50);
	ON(&gconf, 51, 50);
	ON(&gconf, 51, 51);
	ON(&gconf, 50, 51);
	*/
	InitWindow(WIDTH, HEIGHT, "Game of life");
	ClearBackground(WHITE);


	while (!WindowShouldClose())
	{
		mousePos = GetMousePosition();


		if(!gconf.gameStarted){
			if(IsMouseButtonPressed(0)){
				ON(&gconf, (int)mousePos.y / CELLSIZE, (int)mousePos.x / CELLSIZE);
			}else if(IsMouseButtonPressed(1)){
				OFF(&gconf, (int)mousePos.y / CELLSIZE, (int)mousePos.x / CELLSIZE);
			}
		}
		if(IsKeyPressed('P')){
			gconf.gameStarted = (gconf.gameStarted != 0 ? 0 : 1);
		}

		BeginDrawing();

		ClearBackground(WHITE);

		updateGame(&gconf);
		
		EndDrawing();
	}

	closeGame(&gconf);

	return 0;
}
