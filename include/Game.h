#ifndef _GAME
#define _GAME

//Macro for indexing gArr
#define AT(g,i,j)  ((g)->gArr[(size_t)(i) * (g)->HCCOUNT + (j)])

//Macros for turning on and off a cell
#define ON(g, i, j) ((g)->gArr[(size_t)(i) * (g)->HCCOUNT + (j)] = 1)
#define OFF(g, i, j) ((g)->gArr[(size_t)(i) * (g)->HCCOUNT + (j)] = 0)

#define ONBUF(g, i, j) ((g)->gArrBuff[(size_t)(i) * (g)->HCCOUNT + (j)] = 1)
#define OFFBUF(g, i, j) ((g)->gArrBuff[(size_t)(i) * (g)->HCCOUNT + (j)] = 0)

typedef struct gConfig{
	int WIDTH;
	int HEIGHT;
	int CELLSIZE;
	int HCCOUNT;
	int VCCOUNT;
	int CELLCOUNT;
	int *gArr;
	int *gArrBuff;
	int gameStarted;
} gConfig;

void updateGame(gConfig * gConf);
int initGame(gConfig * gConf, int WIDTH, int HEIGHT, int CELLSIZE);
int closeGame(gConfig *gConf);
void drawGame(gConfig *gConf);

#endif
