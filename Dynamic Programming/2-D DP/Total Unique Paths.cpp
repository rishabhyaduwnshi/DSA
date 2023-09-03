int paths(int i, int j, vector<vector<int>> &results)
{
        
    if(results[i][j] != -1)
        return results[i][j];
        
    if(i == 1 && j == 1)
        return 1;
            
    if(i < 1 || j < 1)
        return 0;
            
    int up = paths(i-1,j,results);
    int down = paths(i,j-1,results);
        
    return results[i][j] = up+down;
}
    
int NumberOfPath(int a, int b)
{
    vector<vector<int>> results(a+1,vector<int>(b+1,-1));
    return paths(a,b,results);
}
