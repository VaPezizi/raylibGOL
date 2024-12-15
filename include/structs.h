#include <stdbool.h>
#include <inttypes.h>

typedef struct{
	bool state;	//1 = alive, 0 = dead	
	uint16_t posX;
	uint16_t posY;
}Cell;
