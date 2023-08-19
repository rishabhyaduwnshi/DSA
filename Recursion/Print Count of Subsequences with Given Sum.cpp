#include<bits/stdc++.h>
using namespace std;

int printSubsequences(int array[], int current_index, int last_index, int current_sum, int sum)
{
    if(current_index == last_index)
    {
        if(current_sum == sum)
            return 1;
        else
            return 0;
    }
    
    int take = printSubsequences(array,current_index+1,last_index,current_sum+array[current_index],sum);
    int not_take = printSubsequences(array,current_index+1,last_index,current_sum,sum);
    
    return take+not_take;
}


int main()
{
    int array[] = {2,1,3,2};
    int sum = 4;
    int size = sizeof(array)/sizeof(int);
    cout<<printSubsequences(array,0,size,0,sum);
    
}
