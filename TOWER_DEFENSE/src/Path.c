#include "../include/Path.h"

void printGrid(char grid[SIZE_X][SIZE_Y]) {
    int i, j;
    for (i = 0; i < SIZE_X; i++) {
        for (j = 0; j < SIZE_Y; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void initializeGrid(char grid[SIZE_X][SIZE_Y]) {
    int i, j;
    for (i = 0; i < SIZE_X; i++) {
        for (j = 0; j < SIZE_Y; j++) {
            grid[i][j] = ' ';
        }
    }
}

int manhattanDistance(Cell c1, Cell c2) {
    return abs(c1.row - c2.row) + abs(c1.col - c2.col);
}


int calculateExtent(Cell start, int direction, char grid[SIZE_X][SIZE_Y]) {
    int extent = 0;
    int currentRow = start.row;
    int currentCol = start.col;

    while (currentRow >= 0 && currentRow < SIZE_X && currentCol >= 0 && currentCol < SIZE_Y) {
        extent++;
        switch (direction) {
            case 0:
                currentRow--;
                break;
            case 1:
                currentCol++;
                break;
            case 2:
                currentRow++;
                break;
            case 3: 
                currentCol--;
                break;
            default:
                break;
        }
    }

    return extent;
}

void generatePath(char grid[SIZE_X][SIZE_Y]) {
    int numTurns, pathLength, currentDirection, i, totalExtent, randomValue, n, s, stepsToAdd;
    int leftDirection, rightDirection;
    int directions[4] = {0};
    int* extents;
    int* randomValues;
    Cell monsterNest;

    initializeGrid(grid);
    monsterNest.row = rand() % (SIZE_X - 6) + 3;
    monsterNest.col = rand() % (SIZE_Y - 6) + 3;

    grid[monsterNest.row][monsterNest.col] = 'M';

    numTurns = 0;
    pathLength = 0;
    currentDirection = 0;

    extents = malloc(4 * sizeof(int));

    for (i = 0; i < 4; i++) {
        extents[i] = calculateExtent(monsterNest, i, grid);
    }

    totalExtent = extents[0] + extents[1] + extents[2] + extents[3];
    randomValue = rand() % totalExtent;

    for (i = 0; i < 4; i++) {
        if (randomValue < extents[i]) {
            currentDirection = i;
            break;
        } else {
            randomValue -= extents[i];
        }
    }

    while (numTurns < 7 || pathLength < 75) {
        if (extents[currentDirection] <= 2) {
            break;
        }

        n = extents[currentDirection];
        randomValues = malloc(n * sizeof(int));
        s = 0;

        for (i = 0; i < n; i++) {
            randomValues[i] = rand() % 4 < 3 ? 1 : 0;
            s += randomValues[i];
        }

        stepsToAdd = s > 3 ? s : 3;

        for (i = 0; i < stepsToAdd; i++) {
            switch (currentDirection) {
                case 0:
                    monsterNest.row--;
                    break;
                case 1:
                    monsterNest.col++;
                    break;
                case 2:
                    monsterNest.row++;
                    break;
                case 3:
                    monsterNest.col--;
                    break;
                default:
                    break;
            }

            grid[monsterNest.row][monsterNest.col] = '*';
            pathLength++;
        }

        leftDirection = (currentDirection + 3) % 4;
        rightDirection = (currentDirection + 1) % 4;

        extents[leftDirection] = calculateExtent(monsterNest, leftDirection, grid);
        extents[rightDirection] = calculateExtent(monsterNest, rightDirection, grid);

        totalExtent = extents[leftDirection] + extents[rightDirection];
        randomValue = rand() % totalExtent;

        if (randomValue < extents[leftDirection]) {
            currentDirection = leftDirection;
        } else {
            currentDirection = rightDirection;
        }

        if (currentDirection != directions[0]) {
            numTurns++;
        }
        directions[0] = currentDirection;

        free(randomValues);
    }

    grid[monsterNest.row][monsterNest.col] = 'P';
    
    if (numTurns >= 7 && pathLength >= 75) {
        printf("Chemin généré avec succès!\n");
    } else {
        generatePath(grid);
    }

    free(extents);
}