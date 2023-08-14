#include <bits/stdc++.h>
using namespace std;

int memoized_array[101][101];

int findCountOfSubsets(int array[], int current_index, int size, int target)
{
    if(current_index == size)
    {
        if(target == 0)
            return 1;
        else
            return 0;
    }
    
    if(memoized_array[current_index][target] != -1)
        return memoized_array[current_index][target];
    
    int include_current_element = findCountOfSubsets(array,current_index+1,size,target-array[current_index]);
    int not_include_current_element = findCountOfSubsets(array,current_index+1,size,target);
    
    return memoized_array[current_index][target] = include_current_element+not_include_current_element;
}





int main()
{
    memset(memoized_array,-1,sizeof(memoized_array));
    int array[] = {2,3,5,6,8,10};
    int size = sizeof(array)/sizeof(int);
    int current_index = 0;
    int sum = 10;
    cout<<"Cout of subsets with give sum is : "<<findCountOfSubsets(array,current_index,size,sum);
  
}
