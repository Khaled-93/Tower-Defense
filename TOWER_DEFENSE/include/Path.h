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

void initializeGrid(char grid[SIZE_Y][SIZE_X]);
void printGrid(char grid[SIZE_Y][SIZE_X]);
int manhattanDistance(Cell c1, Cell c2);
int calculateExtent(Cell start, int direction, char grid[SIZE_Y][SIZE_X]);
void generatePath(char grid[SIZE_Y][SIZE_X]);
int isValidCell(int row, int col);
int isValidMove(int row, int col, int currentDirection, char grid[SIZE_Y][SIZE_X]);

#endif
