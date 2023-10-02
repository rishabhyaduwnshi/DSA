void count_islands(vector<vector<int>> &grid, vector<vector<bool>> &visited, int current_row, int current_col,
            vector<pair<int,int>> &pairs, int base_row, int base_col)
            
{
    int n = grid.size();
    int m = grid[0].size();
        
    if(current_row >= 0 && current_row < n && current_col >= 0 && current_col < m)
    {
        if(grid[current_row][current_col] == 1 && visited[current_row][current_col] == false)
        {
                
            visited[current_row][current_col] = true;
            pairs.push_back({current_row-base_row, current_col-base_col});
            
            count_islands(grid,visited,current_row-1,current_col,pairs,current_row,current_col);
            count_islands(grid,visited,current_row+1,current_col,pairs,current_row,current_col);
            count_islands(grid,visited,current_row,current_col-1,pairs,current_row,current_col);
            count_islands(grid,visited,current_row,current_col+1,pairs,current_row,current_col);
        }
    }
        
        
}
  
int countDistinctIslands(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
        
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    set<vector<pair<int,int>>> st;
        
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j] == false && grid[i][j] == 1)
            {
                vector<pair<int,int>> pairs;
                count_islands(grid,visited,i,j,pairs,i,j);
                st.insert(pairs);
            }
        }
    }
        
    return st.size();
}
