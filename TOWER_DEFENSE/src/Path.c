#include "../include/Path.h"

void printGrid(char grid[SIZE_Y][SIZE_X]) {
    int i, j;
    for (i = 0; i < SIZE_Y; i++) {
        for (j = 0; j < SIZE_X; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void initializeGrid(char grid[SIZE_Y][SIZE_X]) {
    int i, j;
    for (i = 0; i < SIZE_Y; i++) {
        for (j = 0; j < SIZE_X; j++) {
            grid[i][j] = ' ';
        }
    }
}

int manhattanDistance(Cell c1, Cell c2) {
    return abs(c1.row - c2.row) + abs(c1.col - c2.col);
}

int isValidCell(int row, int col) {
    return row >= 0 && row < SIZE_Y && col >= 0 && col < SIZE_X;
}

Cell getOppositeCell(Cell cell, int direction) {
    Cell oppositeCell;
    switch (direction) {
        case 0:
            oppositeCell.row = cell.row + 2;
            oppositeCell.col = cell.col;
            break;
        case 1:
            oppositeCell.row = cell.row;
            oppositeCell.col = cell.col - 2;
            break;
        case 2:
            oppositeCell.row = cell.row - 2;
            oppositeCell.col = cell.col;
            break;
        case 3:
            oppositeCell.row = cell.row;
            oppositeCell.col = cell.col + 2;
            break;
        default:
            oppositeCell = cell;
            break;
    }
    return oppositeCell;
}

int isValidMove(int row, int col, int currentDirection, char grid[SIZE_Y][SIZE_X]) {
    int i, j;
    Cell tempCell1, tempCell2, oppositeCell;

    for (i = row - 2; i <= row + 2; i++) {
        for (j = col - 2; j <= col + 2; j++) {
            tempCell1.row = row;
            tempCell1.col = col;
            tempCell2.row = i;
            tempCell2.col = j;
            
            if (isValidCell(i, j) && grid[i][j] == '*') {
                if (manhattanDistance(tempCell1, tempCell2) <= 2) {
                    if (i != row || j != col) {
                        oppositeCell = getOppositeCell(tempCell1, currentDirection);
                        if (manhattanDistance(tempCell2, oppositeCell) > 2) {
                            if (row >= 2 && row < SIZE_Y - 2 && col >= 2 && col < SIZE_X - 2) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return 1;
}

int calculateExtent(Cell start, int direction, char grid[SIZE_Y][SIZE_X]) {
    int extent = 0;
    int currentCol, currentRow;
    int dRow = 0, dCol = 0;

    if (start.row < 0 || start.row >= SIZE_Y || start.col < 0 || start.col >= SIZE_X) {
        return 0;
    }

    if (direction == 0) {
        dRow = -1;
    } else if (direction == 1) {
        dRow = 1;
    } else if (direction == 2) {
        dCol = 1;
    } else if (direction == 3) {
        dCol = -1;
    } else {
        printf("Direction invalide.\n");
        return 0;
    }

    currentRow = start.row + dRow;
    currentCol = start.col + dCol;
    if (grid[currentRow][currentCol] == '*' || grid[currentRow][currentCol] == 'M') {
        return extent;
    }
    if (grid[currentRow+dRow][currentCol+dCol] == '*' || grid[currentRow+dRow][currentCol+dCol] == 'M') {
        return extent;
    }
    while (currentRow > 0 && currentRow < SIZE_Y - 1 && currentCol > 0 && currentCol < SIZE_X - 1) {
        if (grid[currentRow+(2*dRow)][currentCol+(2*dCol)] == '*' || grid[currentRow+(2*dCol)][currentCol+(2*dCol)] == 'M' && (currentCol+(2*dCol))< SIZE_X && (currentRow+(2*dRow))< SIZE_Y) {
            break;
        }

        extent++;

        currentRow += dRow;
        currentCol += dCol;
    }

    return extent;
}


void generatePath(char grid[SIZE_Y][SIZE_X]) {
    int numTurns = 0;
    int currentLength = 0;
    int directionOffsets[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int extent, currentDirection, s, i, numSteps, leftExtent, rightExtent, totalExtent;
    Cell nest;

    while (1) {
        initializeGrid(grid);
        nest.row = rand() % (SIZE_Y - 6) + 3;
        nest.col = rand() % (SIZE_X - 6) + 3;

        grid[nest.row][nest.col] = 'M';

        currentDirection = rand() % 4;

        while (1) {
            extent = calculateExtent(nest, currentDirection, grid);

            if (extent <= 2) {
                numTurns = 0;
                currentLength = 0;
                break;
            } else {
                s = 0;
                for (i = 0; i < extent; i++) {
                    s += rand() % 4 < 3 ? 1 : 0;
                }

                numSteps = (s < 3) ? 3 : s;
                currentLength += numSteps;

                for (i = 0; i < numSteps; i++) {
                    nest.row += directionOffsets[currentDirection][0];
                    nest.col += directionOffsets[currentDirection][1];

                    if (nest.row >= 0 && nest.row < SIZE_Y && nest.col >= 0 && nest.col < SIZE_X) {
                        if( currentLength >= 75 && i == numSteps-1){
                            grid[nest.row][nest.col] = 'P';
                        }else{
                            grid[nest.row][nest.col] = '*';
                        }
                    }
                }

                leftExtent = calculateExtent(nest, (currentDirection + 3) % 4, grid);
                rightExtent = calculateExtent(nest, (currentDirection + 1) % 4, grid);

                totalExtent = leftExtent + rightExtent;

                if (totalExtent > 0 && rand() % totalExtent < leftExtent) {
                    currentDirection = (currentDirection + 3) % 4;
                } else {
                    currentDirection = (currentDirection + 1) % 4;
                }

                numTurns++;
            }

            if (numTurns >= 7 && currentLength >= 75) {
                printf("Chemin généré avec succès.\n");
                return;
            }
        }
    }
}

