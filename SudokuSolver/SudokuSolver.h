#pragma once
#include <iostream>
#define EMPTY 0 //define 0 to indicate cells that have not been filled yet
#define N 9     // N is used specify the board dimensions which are N x N 

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

