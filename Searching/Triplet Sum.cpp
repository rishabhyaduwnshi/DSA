#include <bits/stdc++.h>
using namespace std;

bool twoSum(int array[], int size, int target_sum, int start_index)
{
    int i=start_index;
    int j=size-1;
    
    while(i < j)
    {
        int sum = array[i]+array[j];
        if(sum == target_sum)
            return true;
            
        else if(sum > target_sum)
            j--;
        else
            i++;
    }
    return false;
}


bool tripletSum(int array[], int size, int target_sum)
{
    for(int i=0;i<size-2;i++)
    {
        if(twoSum(array,size,target_sum-array[i],i+1))
            return true;
    }
    
    return false;
}

int main()
{
    int array[] = {10,20,30,40,50,100};
    int size = sizeof(array)/sizeof(int);
    if(tripletSum(array,size,25))
        cout<<"Yes";
    else
        cout<<"No";
}
