vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result_array;
        int i = 0,j,k;
        int result;
        for(i=0;i<nums.size();i++)
        {
            //for avoiding same elements
            if(i > 0 && nums[i] == nums[i-1])
                continue;
                
            j = i+1;
            k = nums.size()-1;
            while(j < k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum > 0)
                    k--;
                else if(sum < 0)
                    j++;
                else
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    j++;
                    k--;
                    result_array.push_back(temp);

                    //for avoiding same elements
                    while(j < k && nums[j] == nums[j-1])
                        j++;
                    while(j < k && nums[k] == nums[k+1])
                        k--;
                }
            }
        }
        return result_array;
    }
