void bfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &grid)
{
    visited[row][col] = true;
    queue<pair<int,int>> q;
    q.push({row,col});
      
    int total_row = grid.size();
    int total_col = grid[0].size();
      
    while(q.empty() == false)
    {
        int current_row = q.front().first;
        int current_col = q.front().second;
        q.pop();
          
        //traverse the neighbours
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nrow = current_row+i;
                int ncol = current_col+j;
                  
                //now check if neighbour_row and neighbour_col are valid
                if(nrow >= 0 && nrow < total_row && col >= 0 && ncol < total_col
                    && grid[nrow][ncol] == '1' && visited[nrow][ncol] == false)
                { 
                    visited[nrow][ncol] = true;
                    q.push({nrow,ncol});
                }
            }
        }
    }
      
}
  
// Function to find the number of islands.
int numIslands(vector<vector<char>>& grid) 
{
    //create a adjcency List
    int n = grid.size();
    int m = grid[0].size();
        
    vector<vector<bool>> visited(n, vector<bool> (m,false));
    int count = 0;
        
    for(int row=0; row<n; row++)
    {
        for(int col = 0; col<m; col++)
        {
            if(visited[row][col] == false && grid[row][col] == '1')
            {
                count++;
                bfs(row,col,visited,grid);
            }
        }
            
    }
    return count;
}
