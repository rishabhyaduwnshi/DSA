//recursive approach
int pathSum(vector<vector<int>>& triangle, int n,int i, int j, vector<vector<int>>& results)
{
    if(results[i][j] != -1)
        return results[i][j];
    
    if(i == n-1) //this condition takes care of diagonal case
        return triangle[i][j];
            
    int down = triangle[i][j] + pathSum(triangle, n, i+1, j,results);
    int diagonal = triangle[i][j] + pathSum(triangle, n, i+1, j+1,results);
        
    return results[i][j] = min (down, diagonal);
}
  
int minimizeSum(int n, vector<vector<int>>& triangle) 
{
    vector<vector<int>> results(n+1, vector<int>(n+1,-1));
    return pathSum(triangle,n,0,0,results);
}
