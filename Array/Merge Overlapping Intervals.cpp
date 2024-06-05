#using sorting
vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        vector<int> start = intervals[0];

        for(int i=1;i<intervals.size();i++)
        {
            if(start[1] >= intervals[i][0])
                start[1] =  max(intervals[i][1],start[1]);
            else
            {   
                result.push_back(start);
                start = intervals[i];
            }
        }

        result.push_back(start);
        return result;
    }
