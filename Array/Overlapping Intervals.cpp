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
