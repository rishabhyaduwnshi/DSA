int count(vector<int> &array, int current_index, int current_sum, int total_sum, vector<vector<int>> &results)
{
    if(current_index == array.size())
    {
        if(current_sum == total_sum)
            return 1;
        else
            return 0;
    }
        
    if(results[current_index][current_sum] != -1)
        return results[current_index][current_sum];
        
    int not_take = count(array,current_index+1,current_sum,total_sum, results)%1000000007;
    int take = 0;
        
    if(array[current_index] <= total_sum-current_sum)
        take = count(array,current_index+1,current_sum+array[current_index],total_sum, results)%1000000007;
            
    return results[current_index][current_sum] = (take+not_take)%1000000007;
}
    
int countPartitions(int n, int d, vector<int>& arr) 
{
    int total_sum = 0;
    for(auto it : arr)
        total_sum += it;
            
    vector<vector<int>> results(arr.size()+1,vector<int>(total_sum+1,-1));    
    if(total_sum-d < 0 || (total_sum-d)%2 == 1)
        return 0;
        
    int sum = (total_sum-d)/2;
    return count(arr,0,sum,total_sum,results);
}
