//recursive approach
int maxPathSum(vector<vector<int>> &matrix, int n, int i, int j, vector<vector<int>> &results)
{
        
    if(j < 0 || j >= n)
        return INT_MIN;
            
    if(i == 0)
        return matrix[i][j];
            
    if(results[i][j] != -1)
        return results[i][j];
            
    int left = matrix[i][j] + maxPathSum(matrix,n,i-1,j,results);
    int right_diagonal = matrix[i][j] + maxPathSum(matrix,n,i-1,j+1,results);
    int left_diagonal = matrix[i][j] + maxPathSum(matrix,n,i-1,j-1,results);
        
    return results[i][j] =  max(left,max(right_diagonal,left_diagonal));
        
}
    
int maximumPath(int N, vector<vector<int>> Matrix)
{
    int current_max = INT_MIN;
    vector<vector<int>> results(N,vector<int>(N,-1)); 
    for(int j=0;j<N;j++)
        current_max = max(current_max,maxPathSum(Matrix,N,N-1,j, results));
        
    return current_max;
}
