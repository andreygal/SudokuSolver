#include "SudokuSolver.h"
#include <iostream>

bool SolveSudoku(int grid[N][N])
{
	int row, col;
	if (!FindEmptyLocation(grid, row, col))
		return true;

	for (int num = 1; num <= 9; num++)
	{
		if (isSafe(grid, row, col, num))
		{
			grid[row][col] = num;

			if (SolveSudoku(grid))
				return true;

			// failure, unmake & try again
			grid[row][col] = EMPTY;
		}
	}
	return false; // this triggers backtracking
}

bool FindEmptyLocation(int grid[N][N], int &row, int &col)
{
	//scan the matrix for an empty cell
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == EMPTY)
				return true;
	return false;
}

bool UsedInRow(int grid[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

bool UsedInCol(int grid[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow][col + boxStartCol] == num)
				return true;
	return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
	/* Check if 'num' is not already placed in current row,
	current column and current 3x3 box */
	return !UsedInRow(grid, row, num) &&
		!UsedInCol(grid, col, num) &&
		!UsedInBox(grid, row - row % 3, col - col % 3, num);
}

void printGrid(int grid[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			printf("%2d", grid[row][col]);
		printf("\n");
	}
}

