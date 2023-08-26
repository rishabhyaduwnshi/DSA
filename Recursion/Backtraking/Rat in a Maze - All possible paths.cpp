// C++ implementation of the above approach
#include <bits/stdc++.h>
#define MAX 5
using namespace std;

	
void getallpath(int matrix[MAX][MAX], int size, int current_row, 
                        int current_col, vector<string> &ans, string current_result)
{
    //
	if(current_row >= size or current_col >= size or current_row <0 or 
	                        current_col <0 or matrix[current_row][current_col] == 0)
	    return;
		
	if(current_row == size-1 and current_col == size-1)
	{
		ans.push_back(current_result);
		return;
	}
		
	matrix[current_row][current_col] = 0; //makes the current cell as 0 for preventing looping
		
	getallpath(matrix,size,current_row-1,current_col,ans,current_result+"U");
	getallpath(matrix,size,current_row,current_col+1,ans,current_result+"R");
	getallpath(matrix,size,current_row,current_col-1,ans,current_result+"L");
	getallpath(matrix,size,current_row+1,current_col,ans,current_result+"D");
		
	matrix[current_row][current_col] = 1; //making it back as 1
		
	return ;
}
	
vector<string> findPath(int matrix[MAX][MAX], int size) 
{
	vector<string> ans;
	getallpath(matrix,size,0,0,ans,"");
	return ans;
}

int main()
{
	int matrix[MAX][MAX] = { { 1, 0, 0, 0, 0 },
						{ 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 0, 1 },
						{ 0, 0, 0, 0, 1 },
						{ 0, 0, 0, 0, 1 } };
						
	int size = sizeof(matrix) / sizeof(matrix[0]); 
	vector<string> ans = findPath(matrix, size);
	for(auto i : ans)
	cout<<i<<" ";

	return 0;
}
