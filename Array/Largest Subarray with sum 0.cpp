int maxLen(vector<int>&a, int n)
    {   
        map<int,int> hash_map;
        int current_max_length = 0;
        int current_sum = 0;
        
        for(int i=0;i<n;i++)
        {
            current_sum += a[i];
            if(current_sum == 0)
                current_max_length = i+1;
            
            if(hash_map.find(current_sum) != hash_map.end())
            {
                int last_seen_index = hash_map[current_sum];
                current_max_length = max(current_max_length,i-last_seen_index);
            }
            else
            {
                hash_map.insert({current_sum,i});
            }
        }
        
        return current_max_length;
    }
