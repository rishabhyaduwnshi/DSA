#rotate a mtrix by 90 degree
#first swap matrix[i][j] with matrix[j][i]
#swap every row


    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
        
    }
};
