#include<bits/stdc++.h>
using namespace std;

//same element can be considered more than once

void findSum(int array[], int current_index, int last_index, int current_sum, 
                    int total_sum, vector<int> temp, set<vector<int>> &result)
{
        
    if(current_index == last_index)
    {
        if(current_sum == total_sum)
            result.insert(temp);
        return;
    }
    
    if(current_sum+array[current_index] <= total_sum)
    {
        temp.push_back(array[current_index]);
        findSum(array,current_index,last_index,current_sum+array[current_index],total_sum,temp,result);
        temp.pop_back();
    }
    findSum(array,current_index+1,last_index,current_sum,total_sum,temp,result);
    
}



int main()
{
    int array[] = {1,2,1};
    int size = sizeof(array)/sizeof(int);
    int sum = 3;
    vector<int> temp;
    set<vector<int>> result;
    findSum(array,0,size,0,sum,temp,result);
    
    for(auto it : result)
    {
        for(int x : it)
            cout<<x<<" ";
        cout<<endl;
    }
}
