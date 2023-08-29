//bottom_up approch
int minimumEnergy(vector<int>& height, int n) 
{
    vector<int> results(n,0);
    results[0] = 0;
        
    for(int i=1;i<n;i++)
    {
        int enery_for_first_step  = results[i-1]+abs(height[i]-height[i-1]);
        int enery_for_second_step = INT_MAX;
            
        if(i>1)
            enery_for_second_step = results[i-2]+abs(height[i]-height[i-2]);
        results[i] = min(enery_for_first_step,enery_for_second_step);
    }
        
    return results[n-1];
}



//recursive solution
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
