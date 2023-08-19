#include<bits/stdc++.h>
using namespace std;

bool printSubsequences(int array[], int current_index, int last_index, int current_sum, int sum, vector<int> &result)
{
    if(current_index == last_index)
    {
        if(current_sum == sum)
        {
            for(int x : result)
                cout<<x<<" ";
            return true;
        }
        else
            return false;
    }
    
    result.push_back(array[current_index]);
    if(printSubsequences(array,current_index+1,last_index,current_sum+array[current_index],sum,result))
        return true;
    
    result.pop_back();
    if(printSubsequences(array,current_index+1,last_index,current_sum,sum,result))
        return true;
        
    return false;
}


int main()
{
    int array[] = {2,1,3,2};
    int sum = 4;
    int size = sizeof(array)/sizeof(int);
    vector<int> result;
    printSubsequences(array,0,size,0,sum,result);
    
}
