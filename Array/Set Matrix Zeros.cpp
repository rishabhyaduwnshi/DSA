//can be solved using contant space

void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row_array(n,1);
        vector<int> col_array(m,1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    row_array[i] = 0;
                    col_array[j] = 0;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row_array[i] == 0 || col_array[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
