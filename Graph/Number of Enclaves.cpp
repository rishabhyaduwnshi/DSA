void check_paths(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
{
    int n = grid.size();
    int m = grid[0].size();
        
    if(i >= 0 && i < n && j >= 0 && j < m)
    {
        if(grid[i][j] == 1 && visited[i][j] == false)
        {
            visited[i][j] = true;
            check_paths(grid,visited,i-1,j);
            check_paths(grid,visited,i+1,j);
            check_paths(grid,visited,i,j+1);
            check_paths(grid,visited,i,j-1);
        }
    }
        
}
    
int numberOfEnclaves(vector<vector<int>> &grid) 
{
    int n = grid.size();
    int m = grid[0].size();
        
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    vector<vector<int>> grid_copy = grid;
        
    //traverse first and last row
    for(int j=0;j<m;j++)
    {
        if(grid[0][j] == 1 && visited[0][j] == false)
            check_paths(grid_copy,visited,0,j);
            
        if(grid[n-1][j] == 1 && visited[n-1][j] == false)
            check_paths(grid_copy,visited,n-1,j);
    }
        
    //traverse first and last column
    for(int i=0;i<n;i++)
    {
        if(grid[i][0] == 1 && visited[i][0] == false)
            check_paths(grid_copy,visited,i,0);
            
        if(grid[i][m-1] == 1 && visited[i][m-1] == false)
            check_paths(grid_copy,visited,i,m-1);
    }
        
    int count = 0;
        
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            if(grid_copy[i][j] == 1 && visited[i][j] == false)
                count++;
        }
    }
        
    return count;
}
