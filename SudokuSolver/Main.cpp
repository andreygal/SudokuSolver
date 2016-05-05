#include <iostream>
#include "SudokuSolver.h"

int main()
{
	int board[N][N] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
									    { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
	                    { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
	                    { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
	                    { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
	                    { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
	                    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	                    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	                    { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	
	if (SolveSudoku(board))
		printGrid(board);
	else
		std::cout << "No solution exists" << std::endl;

	return 0;
}