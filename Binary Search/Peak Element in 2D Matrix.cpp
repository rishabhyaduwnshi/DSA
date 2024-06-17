int find_max(vector<vector<int>>& matrix, int n, int m, int column_no)
    {
        int current_max = INT_MIN;
        int row_no = -1;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][column_no] > current_max)
            {
                current_max = matrix[i][column_no];
                row_no = i;
            }
        }

        return row_no;
    }

    vector<int> findPeakGrid(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0;
        int end = m-1;
        
        while(start <= end)
        {
            int col = (start+end)/2;
            int row = find_max(matrix,n,m,col);

            int left = (col-1 >= 0) ? matrix[row][col-1] : -1;
            int right = (col+1 < m) ? matrix[row][col+1] : -1;

            if(matrix[row][col] > left && matrix[row][col] > right)
                return {row,col};
            else if(left > matrix[row][col])
                end = col-1;
            else
                start = col+1;
        }
        return {-1,-1};
    }
