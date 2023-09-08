int checkForSum(vector<int> array, int current_index, int current_sum, vector<vector<int>> &results)
{
    if(current_sum == 0)
        return 1;
        
    if(current_index == array.size())
        return 0;
            
    if(results[current_index][current_sum] != -1)
        return results[current_index][current_sum];
            
    int not_take_current_element = checkForSum(array,current_index+1,current_sum, results);
    int take_current_element = 0;
        
    if(array[current_index] <= current_sum)
        take_current_element = checkForSum(array,current_index+1,current_sum-array[current_index], results);
            
    return results[current_index][current_sum] = take_current_element | not_take_current_element;
        
}
    
    
bool isSubsetSum(vector<int>array, int sum)
{
    int i = array.size()+1;
    int j = sum+1;
        
    vector<vector<int>> results(i,vector<int>(j,-1));
    if(checkForSum(array,0,sum, results) == 0)
        return false;
    else
        return true;
}
