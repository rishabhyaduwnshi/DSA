#using constant extra space
#we use the first row and column as flag for setting 0
#first the first column we use an extra variable column_0
void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int column_0 = 1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        column_0 = 0;
                }
            }
        }

        //now leave the first row and column currently and iterate from second

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if(matrix[0][0] == 0)
        {
            for(int j=0;j<m;j++)
            matrix[0][j] = 0;
        }

        if(column_0 == 0)
        {
            for(int i=0;i<n;i++)
                matrix[i][0] = 0;
        }
    }
};
