long long find_days(vector<int>& bloomDay, int m, int k, int start)
    {
        int current_count = 0;
        int bouquets = 0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i] <= start)
            {
                current_count++;
                if(current_count == k)
                {
                    bouquets++;
                    current_count = 0;
                }
            }
            else
                current_count = 0;
        }

        return (bouquets >= m) ? start : 1e9;
    }

    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();
        long long flowers = (long long)m * k;
        if(flowers > n)
            return -1;
        
        int min_days = *min_element(bloomDay.begin(),bloomDay.end());
        int max_days = *max_element(bloomDay.begin(),bloomDay.end());

        long long result = 1e9;
        int start = min_days;
        int end = max_days;
        
        while(start <= end)
        {
            int mid = (start+end)/2;
            if(find_days(bloomDay,m,k,mid) != 1e9)
            {
                result = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return result;
    }
