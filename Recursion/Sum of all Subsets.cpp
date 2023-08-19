#include<bits/stdc++.h>
using namespace std;

void generateSubsets(int array[], int current_index, int last_index, vector<int> &temp,vector<int> &result)
{
    if(current_index == last_index)
    {
        int sum = 0;
        for(auto it : temp)
            sum += it;
        result.push_back(sum);
        return;
    }
    
    temp.push_back(array[current_index]);
    generateSubsets(array,current_index+1,last_index,temp,result);
    temp.pop_back();
    generateSubsets(array,current_index+1,last_index,temp,result);
}



int main()
{
    int array[] = {3,1,2};
    int size = sizeof(array)/sizeof(int);
    vector<int> temp;
    vector<int> result;
    generateSubsets(array,0,size,temp,result);
    sort(result.begin(),result.end());
    
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
}
