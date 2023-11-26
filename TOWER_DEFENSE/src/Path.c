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
    int i,j;
    for (i = 0; i < SIZE_X; ++i) {
        for (j = 0; j < SIZE_Y; ++j) {
            if (strcmp(grid[i][j], "true") == 0) {
                printf("* ");
            } else {
                printf("%s ", grid[i][j]);
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
    int initialDirection;
    int directions[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int turnCount = 0;
    int pathLength = 0;
    Cell currentCell;
    int currentDirection;
    int currentExtent = 0;
    int randomValue;
    int leftDirection;
    int rightDirection;
    int leftExtent;
    int rightExtent;
    Cell leftCell;
    Cell rightCell;
    int totalExtent;
    int minDistance;
    int tooClose;
    int i, j;
    Cell tempCell;

    monsterNest.row = rand() % (SIZE_X - 6) + 3;
    monsterNest.col = rand() % (SIZE_Y - 6) + 3;

    currentCell = monsterNest;

    initializeGrid(grid);

    grid[monsterNest.row][monsterNest.col] = "M";

    initialDirection = rand() % 4;

    currentDirection = initialDirection;

    while (turnCount < MIN_TURN_COUNT || pathLength < MIN_PATH_LENGTH) {
    currentExtent = 0;
    while (currentExtent <= 2) {
        randomValue = rand() % 4;
        if (randomValue != 0) {
            currentExtent++;
        }

        currentCell.row += directions[currentDirection][0];
        currentCell.col += directions[currentDirection][1];

        if (!isValid(currentCell) || grid[currentCell.row][currentCell.col] != NULL) {
            break;
        }

        minDistance = 1;
        tooClose = 0;

        for (i = -minDistance; i <= minDistance; ++i) {
            for (j = -minDistance; j <= minDistance; ++j) {
                tempCell.row = currentCell.row + i;
                tempCell.col = currentCell.col + j;

                if (isValid(tempCell) && grid[tempCell.row][tempCell.col] != NULL) {
                    tooClose = 1;
                    break;
                }
            }
            if (tooClose) {
                break;
            }
        }

        if (tooClose || pathLength >= MIN_PATH_LENGTH) {
            break;
        }

        grid[currentCell.row][currentCell.col] = "true";
        pathLength++;
    }

        leftDirection = (currentDirection + 3) % 4;
        rightDirection = (currentDirection + 1) % 4;

        leftExtent = 0;
        rightExtent = 0;

        leftCell = currentCell;
        while (leftExtent <= 2) {
            leftCell.row += directions[leftDirection][0];
            leftCell.col += directions[leftDirection][1];

            if (!isValid(leftCell) || grid[leftCell.row][leftCell.col] != NULL) {
                break;
            }

            leftExtent++;
        }

        rightCell = currentCell;
        while (rightExtent <= 2) {
            rightCell.row += directions[rightDirection][0];
            rightCell.col += directions[rightDirection][1];

            if (!isValid(rightCell) || grid[rightCell.row][rightCell.col] != NULL) {
                break;
            }

            rightExtent++;
        }

        totalExtent = leftExtent + rightExtent;
        if (totalExtent != 0) {
            randomValue = rand() % totalExtent;
            if (randomValue < leftExtent) {
                currentDirection = leftDirection;
            } else {
                currentDirection = rightDirection;
            }
        }

        if (currentDirection != initialDirection) {
            turnCount++;
        }
    }
}

