#include <iostream>

using namespace std;

// N is the size of the 2D matrix N*N
#define N 9

/* A utility function to print grid */
void print(int arr[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
	
	//checking in same row -> column will change
	for (int x = 0; x <= 8; x++)
		if (grid[row][x] == num)
			return false;
    
    //checking in same column -> row will change
	for (int x = 0; x <= 8; x++)
		if (grid[x][col] == num)
			return false;

    
    //for checking the current 3*3 matrix
	int startRow = row - row % 3;
	int startCol = col - col % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i+startRow][j+startCol] == num)
				return false;

	return true;
}

bool solveSudoku(int grid[N][N], int row, int col)
{
	if (row == N - 1 && col == N)
		return true;

	if (col == N) 
	{
		row++;
		col = 0;
	}
	
	if (grid[row][col] > 0)
		return solveSudoku(grid, row, col + 1);

	for (int num = 1; num <= N; num++)
	{
		if (isSafe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solveSudoku(grid, row, col + 1))
				return true;
		}
		grid[row][col] = 0;
	}
	return false;
}

// Driver Code
int main()
{
	// 0 means unassigned cells
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

	if (solveSudoku(grid, 0, 0))
		print(grid);
	else
		cout << "no solution exists " << endl;

	return 0;
	// This is code is contributed by Pradeep Mondal P
}