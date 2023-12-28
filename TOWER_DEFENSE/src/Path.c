#include "../include/Path.h"

void initializeGrid(char* grid[SIZE_X][SIZE_Y]) {
    int i, j;
    for (i = 0; i < SIZE_X; ++i) {
        for (j = 0; j < SIZE_Y; ++j) {
            grid[i][j] = " ";
        }
    }
}

void printGrid(char* grid[SIZE_X][SIZE_Y]) {
    int i, j;
    for (i = 0; i < SIZE_X; ++i) {
        for (j = 0; j < SIZE_Y; ++j) {
            if (strcmp(grid[i][j], "true") == 0) {
                printf("*");
            } else {
                printf("%s", grid[i][j]);
            }
        }
        printf("\n");
    }
}


int manhattanDistance(Cell c1, Cell c2) {
    return abs(c1.row - c2.row) + abs(c1.col - c2.col);
}

int isValid(Cell cell) {
    return cell.row >= 0 && cell.row < SIZE_X && cell.col >= 0 && cell.col < SIZE_Y;
}

void generatePath(char* grid[SIZE_X][SIZE_Y]) {
    Cell monsterNest;
    Cell nextCell;
    int pathLength, step, i, turnCount, currentDirection;
    int directions[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    initializeGrid(grid);

    monsterNest.row = rand() % (SIZE_X - 6) + 3;
    monsterNest.col = rand() % (SIZE_Y - 6) + 3;

    grid[monsterNest.row][monsterNest.col] = "M";

    pathLength = 0;
    turnCount = 0;
    currentDirection = rand() % 4; 

    while (pathLength < MIN_PATH_LENGTH || turnCount < MIN_TURN_COUNT) {
        step = rand() % 4 + 1;

        for (i = 0; i < step; ++i) {
            nextCell.row = monsterNest.row + directions[currentDirection][0];
            nextCell.col = monsterNest.col + directions[currentDirection][1];

            if (!isValid(nextCell) || grid[nextCell.row][nextCell.col] != NULL) {
                currentDirection = rand() % 4;
            } else {
                grid[nextCell.row][nextCell.col] = "true";
                monsterNest = nextCell;
                pathLength++;
            }
        }

        currentDirection = rand() % 4;
        turnCount++;
    }
}