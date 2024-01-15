// generates each row
vector<int> generate_row(int row_no)
    {
        vector<int> temp;
        temp.push_back(1);
        int result = 1;
        for(int col_no=1;col_no<row_no;col_no++)
        {
            result = result*(row_no-col_no);
            result = result/col_no;
            temp.push_back(result);
        }
        return temp;
    }

    //1 based indexing
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> result;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> temp_row;
            temp_row = generate_row(i);
            result.push_back(temp_row);
        }

        return result;
    }
