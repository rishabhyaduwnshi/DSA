#include<bits/stdc++.h>
using namespace std;

void generateSubsets(vector<int> &array, int current_index, vector<int> &temp, vector<vector<int>> &set_result)
{
    set_result.push_back(temp);
    
    for(int i=current_index;i<array.size();i++)
    {
        if(i>current_index && array[i] == array[i-1])
            continue;
            
        temp.push_back(array[i]);
        generateSubsets(array,i+1,temp,set_result);
        temp.pop_back();
    }
}



int main()
{
    vector<int> array = {4,4,4,1,4};
    int size = sizeof(array)/sizeof(int);
    vector<int> temp;
    vector<vector<int>> result;
    sort(array.begin(),array.end());
    generateSubsets(array,0,temp,result);
    
    for(auto it : result)
    {
        for(auto x : it)
            cout<<x<<" ";
        cout<<endl;
    }
    
}
