int lenOfLongSubarr(int array[],  int n, int k) 
    { 
        map<int,int> mappings;
        int current_sum = 0;
        int max_length = 0;
        
        for(int i=0;i<n;i++)
        {
            current_sum += array[i];
            if(current_sum == k)
                max_length = max(max_length,i+1);
            
            int remaning_sum = current_sum - k;
            if(mappings.find(remaning_sum) != mappings.end())
            {
                int remaning_sum_length = i - mappings[remaning_sum];
                max_length = max(max_length,remaning_sum_length);
            }
            if(mappings.find(current_sum) == mappings.end())
                mappings[current_sum] = i;
        }
        
        return max_length;
    }
