void fill_ox(vector<vector<char>> &matrix, vector<vector<char>> &result, int i, int j, vector<vector<bool>> &visited)
{
    int n = matrix.size();
    int m = matrix[0].size();
        
    if(i >= 0 && i < n && j >= 0 && j < m)
    {
        if(visited[i][j] == false && matrix[i][j] == 'O')
        {
            result[i][j] = 'O';
            visited[i][j] = true;
            fill_ox(matrix,result,i-1,j,visited);
            fill_ox(matrix,result,i+1,j,visited);
            fill_ox(matrix,result,i,j-1,visited);
            fill_ox(matrix,result,i,j+1,visited);
        }
    }
        
}
    
vector<vector<char>> fill(int n, int m, vector<vector<char>> matrix)
{
        
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    vector<vector<char>> result = matrix;
        
    //first row and last row
    for(int j=0;j<m;j++)
    {
        if(visited[0][j] == false && matrix[0][j] == 'O')
            fill_ox(matrix,result,0,j,visited);
                
        if(visited[n-1][j] == false && matrix[n-1][j] == 'O')
            fill_ox(matrix,result,n-1,j,visited);
    }
        
    //last row and last column
    for(int i=0;i<n;i++)
    {
        if(visited[i][0] == false && matrix[i][0] == 'O')
            fill_ox(matrix,result,i,0,visited);
                
        if(visited[i][m-1] == false && matrix[i][m-1] == 'O')
            fill_ox(matrix,result,i,m-1,visited);
            
    }
        
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            if(matrix[i][j] == 'O' && visited[i][j] == false)
                result[i][j] = 'X';
        }
    }
        
    return result;
}
