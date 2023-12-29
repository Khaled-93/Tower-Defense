#ifndef __PATH
#define __PATH


#include "all.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int row;
    int col;
} Cell;

void initializeGrid(char grid[SIZE_X][SIZE_Y]);
void printGrid(char grid[SIZE_X][SIZE_Y]);
int manhattanDistance(Cell c1, Cell c2);
int calculateExtent(Cell start, int direction, char grid[SIZE_X][SIZE_Y]);
void generatePath(char grid[SIZE_X][SIZE_Y]);

#endif
