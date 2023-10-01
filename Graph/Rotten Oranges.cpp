int orangesRotting(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
        
    queue< pair <pair <int,int>, int>> q;
    vector<vector<bool>> visited(n, vector<bool> (m,false));
        
    int fresh_count = 0;
        
    //push all the rotten oranges at once with at 0 time
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 2)
            {    
                q.push({{i,j},0});
                visited[i][j] = true;
            }
                
            if(grid[i][j] == 1)
                fresh_count++;
        }
    }
        
    int final_time = 0;
    int possible_rows[] = {-1,0,1,0};
    int possible_cols[] = {0,1,0,-1};
    int final_fresh_count = 0;
        
    while(q.empty() == false)
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int c_time = q.front().second;
        final_time = max(final_time,c_time);
        q.pop();
            
        //changing rows & colums
        for(int i=0;i<4;i++)
        {
            int current_row = row+possible_rows[i];
            int current_col = col+possible_cols[i];
                
            //check for valid cells
            if(current_row >= 0 && current_row < n && current_col >= 0 && current_col < m
                && visited[current_row][current_col] == false && grid[current_row][current_col] == 1)
            {
                q.push({{current_row,current_col},c_time+1});
                visited[current_row][current_col] = true;
                final_fresh_count++;
            }
        }
    }
        
    if(fresh_count != final_fresh_count)
        return -1;
        
    return final_time;
}
