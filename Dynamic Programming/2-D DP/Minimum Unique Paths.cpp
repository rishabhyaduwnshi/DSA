int minPath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &results)
{
    if(i == 0 && j == 0)
        return grid[i][j];

    if(i < 0 || j < 0)
        return 1e9;

    if(results[i][j] != -1)
        return results[i][j];

    int up = grid[i][j]+minPath(grid,i-1,j,results);
    int left = grid[i][j]+minPath(grid,i,j-1, results);

    return results[i][j] =  min(up,left);
}

int minSumPath(vector<vector<int>> &grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> results(n,vector<int>(m,-1));
    return minPath(grid,n-1,m-1,results);
}
