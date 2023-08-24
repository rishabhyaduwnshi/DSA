// C++ program to solve N Queen Problem using backtracking

#include <bits/stdc++.h>
#define N 4
using namespace std;

void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}

bool isSafe(int board[N][N], int row, int col)
{
	int row_copy = row; 
	int col_copy = col;
	
	//go upwards diagonally ->both row and column will decrease
	while(row_copy >= 0 && col_copy >= 0)
	{
	    if(board[row_copy][col_copy] == 1)
	        return false;
	   row_copy--;
	   col_copy--;
	}
	
	//go backwards in straight line -> row will be same, column will decrease
	row_copy = row; 
	col_copy = col;
	
	while(col_copy >= 0)
	{
	    if(board[row_copy][col_copy] == 1)
	        return false;
	   col_copy--;
	}
	
	
	//go downwards diagonally -> column will decrease but row will increase
	row_copy = row; 
	col_copy = col;
	
	while(row_copy < N && col_copy >= 0)
	{
	    if(board[row_copy][col_copy] == 1)
	        return false;
	   row_copy++;
	   col_copy--;
	}
	return true;
}


bool solveNQUtil(int board[N][N], int col)
{
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++) 
	{
		if (isSafe(board, i, col)) 
		{
			
			board[i][col] = 1;

			if (solveNQUtil(board, col + 1))
				return true;

			board[i][col] = 0; // while returning, set the value back to 0
		}
	}

	return false;
}


bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }};

	if (solveNQUtil(board, 0) == false) 
	{
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}

int main()
{
	solveNQ();
	return 0;
}
