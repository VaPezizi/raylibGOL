#include <stdio.h>
#include <raylib.h>

const int HEIGHT = 600;
const int WIDTH = 800;

int main(){

	InitWindow(WIDTH, HEIGHT, "Game of life");
	ClearBackground(WHITE);


	while(!WindowShouldClose()){
		BeginDrawing();

		DrawText("Hello World", WIDTH / 2, HEIGHT / 2, 20, BLACK);

		ClearBackground(WHITE);
		EndDrawing();
	}
	

	return 0;
}
