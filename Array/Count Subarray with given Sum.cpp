int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int current_sum = 0;
        int count = 0;

        for(int i=0;i<nums.size();i++)
        {
            current_sum += nums[i];
            int remainder_sum = current_sum - k;
            
            if(mp[remainder_sum] != 0)
                count += mp[remainder_sum];
            mp[current_sum] += 1;
        }
        return count;
    }
