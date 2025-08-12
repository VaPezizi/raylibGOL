#include "Game.h"

#ifndef _RAYLIB
#define _RAYLIB
#include <raylib.h>
#endif

#ifndef _STD
#define _STD
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#endif

void updateGame(gConfig * gConf){
    for (int i = 0; i < gConf->VCCOUNT; i++){
        for (int j = 0; j < gConf->HCCOUNT; j++){
            if(AT(gConf, i, j) == 1){
                DrawRectangle(j * gConf->CELLSIZE, i * gConf->CELLSIZE,
                              gConf->CELLSIZE, gConf->CELLSIZE, BLACK);
                //printf("i: %d, j: %d, \n", j * gConf->CELLSIZE, i * gConf->CELLSIZE);
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
