#include<bits/stdc++.h>
using namespace std;

void printSubsequences(int array[], int current_index, int last_index, int current_sum, int sum, vector<int> &result)
{
    if(current_index == last_index)
    {
        if(current_sum == sum)
        {
            for(int x : result)
                cout<<x<<" ";
            cout<<endl;
        }
        return;
    }
    
    result.push_back(array[current_index]);
    printSubsequences(array,current_index+1,last_index,current_sum+array[current_index],sum,result);
    
    result.pop_back();
    printSubsequences(array,current_index+1,last_index,current_sum,sum,result);
}


int main()
{
    int array[] = {1,2,1};
    int sum = 2;
    int size = sizeof(array)/sizeof(int);
    vector<int> result;
    printSubsequences(array,0,size,0,2,result);
    
}
