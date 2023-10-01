vector<vector<int>>nearest(vector<vector<int>>grid)
{
    int n = grid.size();
	  int m = grid[0].size();
	    
	bool visited[n][m];
	vector<vector<int>> result(n, vector<int> (m,0));
	    
	queue<pair<pair<int,int>,int>> q;
	    
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
	        if(grid[i][j] == 1)
	        {   
	           q.push({{i,j},0});
	           visited[i][j] = true;
	        }
	        else
	        {
	            visited[i][j] = false;
	        }
	    }
    }
	    
	int del_row[] = {-1,0,1,0};
	int del_col[] = {0,1,0,-1};
	    
	    
	while(q.empty() == false)
	{
	    int row = q.front().first.first;
	    int col = q.front().first.second;
	    int dis = q.front().second;
	    q.pop();
	        
	    result[row][col] = dis;
	        
	    for(int i=0;i<4;i++)
	    {
	        int nrow = row+del_row[i];
	        int ncol = col+del_col[i];
	            
	            
	        //check for valid rows & cols
	        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == false)
	        {
	           visited[nrow][ncol] = true;
	           q.push({{nrow,ncol},dis+1});
	        }
	    }
	        
    }
	
	return result;
	

}
