int minEnergy(vector<int>& height, int n, vector<int> &results) 
{
    if(n == 0)
        return 0;
            
    if(results[n] != 0)
        return results[n];
            
    int energy_for_first_step = minEnergy(height,n-1,results) + abs(height[n] - height[n-1]);
    int energy_for_second_step = INT_MAX;
    
    if(n > 1)
        energy_for_second_step = minEnergy(height,n-2,results) + abs(height[n] - height[n-2]);
            
    return results[n] = min(energy_for_first_step,energy_for_second_step);
}
