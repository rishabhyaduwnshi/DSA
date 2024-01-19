vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        int n = intervals.size();
        
        for(int i=0;i<n;i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if(result.empty() == false && end <= result.back()[1])
                continue;
        
            for(int j=i+1;j<n;j++)
            {
                
                if(intervals[j][0] <= end)
                    end = max(end,intervals[j][1]);
                else
                    break;
            }
                
            result.push_back({start,end});
        }
        
        return result;
    }



vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        int n = intervals.size();
        
        for(int i=0;i<n;i++)
        {
            //if the result array is empty or the first element of the last row is greater in the array is greater than the last element
            // of result, then push
            if(result.empty() || intervals[i][0] > result.back()[1])
                result.push_back(intervals[i]);
            else
                result.back()[1] = max(result.back()[1],intervals[i][1]);
        }
        
        return result;
    }
