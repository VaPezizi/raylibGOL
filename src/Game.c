#include "Game.h"

#ifndef _RAYLIB
#define _RAYLIB
#include <raylib.h>
#endif

#ifndef _STD
#define _STD
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#endif

void updateGame(gConfig * gConf){
    
    memcpy(gConf->gArrBuff, gConf->gArr, sizeof(int[gConf->HCCOUNT][gConf->VCCOUNT]));
    if(gConf->gameStarted){
        for (int i = 0; i < gConf->VCCOUNT; i++){
            for (int j = 0; j < gConf->HCCOUNT; j++){

                
                    int count = 0;  //Neighbour count
                    int topIdx = (i - 1 + gConf->VCCOUNT) % gConf->VCCOUNT;
                    int leftIdx = (j - 1 + gConf->HCCOUNT) % gConf->HCCOUNT;
                    int rightIdx = (j + 1) % gConf->HCCOUNT;
                    int bottomIdx = (i + 1) % gConf->VCCOUNT;

                    // Left X pos with safety
                    if (AT(gConf, i, leftIdx))
                    {
                        count++;
                    }
                    if(AT(gConf, topIdx, leftIdx)){
                        count++;
                    }
                    if(AT(gConf, topIdx, j)){
                        count++;
                    }
                    if(AT(gConf, topIdx, rightIdx)){
                        count++;
                    }
                    if(AT(gConf, i, rightIdx)){
                        count++;
                    }
                    if(AT(gConf, bottomIdx, rightIdx)){
                        count++;
                    }
                    if(AT(gConf, bottomIdx, j))
                        count++;
                    if(AT(gConf, bottomIdx, leftIdx))
                        count++;

                    if(AT(gConf, i, j) == 1){
                        
                        
                        if(count < 2){
                            OFFBUF(gConf, i, j);
                        }else if(count > 3){
                            OFFBUF(gConf, i, j);
                        }
                        // printf("i: %d, j: %d, \n", j * gConf->CELLSIZE, i * gConf->CELLSIZE);
                    }else if(count == 3){
                        ONBUF(gConf, i, j);
                    }
            }
                
        }
    }
    memcpy(gConf->gArr, gConf->gArrBuff, sizeof(int[gConf->HCCOUNT][gConf->VCCOUNT]));

}

void drawGame(gConfig * gConf){
    for (int i = 0; i < gConf->VCCOUNT; i++){
        for (int j = 0; j < gConf->HCCOUNT; j++){
            if(AT(gConf, i, j) == 1){
		Color color = BLACK;
		if(gConf->colorMode)
			color = (Color) {rand() % 256, rand() % 256, rand() % 256, 255};	//Random color	
                DrawRectangle(j * gConf->CELLSIZE, i * gConf->CELLSIZE,
                            gConf->CELLSIZE, gConf->CELLSIZE, color);
            }
        }
    }
}
int initGame(gConfig * gConf, int WIDTH, int HEIGHT, int CELLSIZE){
    gConf->WIDTH = WIDTH;
    gConf->HEIGHT = HEIGHT;
    gConf->CELLSIZE = CELLSIZE;

    gConf->HCCOUNT = WIDTH / CELLSIZE;
    gConf->VCCOUNT = HEIGHT / CELLSIZE;
    gConf->CELLCOUNT = gConf->HCCOUNT + gConf->VCCOUNT;
    gConf->colorMode = 0;

    srand(time(NULL));

    size_t allocSize = sizeof(int[gConf->HCCOUNT][gConf->VCCOUNT]);

    gConf->gArr = malloc(allocSize);
    gConf->gArrBuff = malloc(allocSize);
    gConf->gameStarted = 0;
    memset(gConf->gArr, 0, allocSize);
    memset(gConf->gArrBuff, 0, allocSize);

    if(gConf->gArr == NULL){
        fprintf(stderr, "Error in gconf memory allocation!");
        return -1;
    }
    else
        return 1;
}

int closeGame(gConfig * gConf){
    free(gConf->gArr);
    free(gConf->gArrBuff);

    return 1;
}
