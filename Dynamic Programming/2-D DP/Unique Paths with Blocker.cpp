int paths(int n, int m, vector<vector<int>> &grid,  vector<vector<int>> &results)
{
        
    if(results[n][m] != -1)
        return results[n][m];
        
    if(n >= 1 && m >= 1 && grid[n-1][m-1] == 0)
        return 0;
        
    if(n == 1 && m == 1)
        return 1;
            
    if(n < 1 || m < 1)
        return 0;
            
    int left = (paths(n-1,m,grid,results))%1000000007;
    int right = (paths(n,m-1,grid,results))%1000000007;
        
    return results[n][m] = (left+right)%1000000007;
}
    
    
int uniquePaths(int n, int m, vector<vector<int>> &grid) 
{
    vector<vector<int>> results(n+1, vector<int>(m+1,-1));
    return paths(n,m,grid,results);
}
