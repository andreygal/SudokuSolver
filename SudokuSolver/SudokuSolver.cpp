#include "SudokuSolver.h"
#include <iostream>

bool FindEmptyLocation(int grid[N][N], int &row, int &col) {
	//scan the matrix for an empty cell
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == EMPTY)
				return true;
	return false;
}

bool ExistsInRow(int grid[N][N], int row, int num) {
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

bool ExistsInCol(int grid[N][N], int col, int num) {
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}
//check to see if the number exists in a local grid
bool ExistsInLocal(int grid[N][N], int start_row, int start_col, int num) {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[start_row + row][start_col + col] == num)
				return true;
	return false;
}
//check if such a number exists in row, column or the local 3x3 grid
bool IsSafe(int grid[N][N], int row, int col, int num) {
	return !ExistsInRow(grid, row, num) &&
		     !ExistsInCol(grid, col, num) &&
		     !ExistsInLocal(grid, row - row % 3, col - col % 3, num);
}

bool SolveSudoku(int grid[N][N]) {
	int row, col;
	//find an empty cell and record its location in row and col
	if (!FindEmptyLocation(grid, row, col))
		return true;
	//test numbers 1 through 9
	for (int num = 1; num <= 9; num++) {
		if (IsSafe(grid, row, col, num)) {
			grid[row][col] = num;
			if (SolveSudoku(grid))
				return true;
			// failure, unmake & try again
			grid[row][col] = EMPTY;
		}
	}
	//backtrack
	return false; 
}

void printGrid(int grid[N][N]) {
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			 std::cout << grid[row][col] << " ";
		std::cout << std::endl; 
	}
}

