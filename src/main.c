#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

#include "constants.h"
#include "structs.h"

int main(){
	InitWindow(WIDTH, HEIGHT, "Game of life");
	ClearBackground(WHITE);
	printf("Koko: %d\n", CELLSIZE);

	printf("Koko: %zu\n", sizeof(Cell));

	Cell * GRID = (Cell*) malloc(sizeof(Cell) * GRIDSIZE);


	for(int col = 0; col < HEIGHT / CELLSIZE; ++col){	//Horizontal
		for(int row = 0; row < WIDTH / CELLSIZE; ++row){	//Vertical
			GRID[row + (WIDTH / CELLSIZE * col)] = (Cell){0,row * CELLSIZE,col * CELLSIZE};
			printf("%d, POSX: %d, POSY: %d\n", row + WIDTH / CELLSIZE * col, row * CELLSIZE, col * CELLSIZE);
			//printf("%d\n", row + row * col);
		}	
	}
	printf("GridSize: %d\n", GRIDSIZE);


	RenderTexture2D target = LoadRenderTexture(WIDTH, HEIGHT);
	BeginTextureMode(target);
	
	for(int i = 0; i < GRIDSIZE; ++i){
		printf("%d, PosX: %d, PosY: %d\n", i, GRID[i].posX, GRID[i].posY);
		DrawRectangle(GRID[i].posX, GRID[i].posY, CELLSIZE, CELLSIZE, GREEN);
	}
	
	EndTextureMode();


	while(!WindowShouldClose()){
		BeginDrawing();

		/*for(int i = 0; i < GRIDSIZE; ++i){
			DrawRectangle(GRID[i].posX, GRID[i].posY, CELLSIZE, CELLSIZE, GREEN);
		}*/
		DrawTextureRec(target.texture, (Rectangle){0, 0, target.texture.width, target.texture.height}, (Vector2){0, 0}, WHITE);
		DrawText("Hello World", WIDTH / 2, HEIGHT / 2, 20, BLACK);

		ClearBackground(WHITE);
		EndDrawing();
	}

	free(GRID);

	return 0;
}
