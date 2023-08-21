#include<bits/stdc++.h>
using namespace std;

void printPermutations(vector<int> &vc, vector<bool> &map, vector<int> &temp, vector<vector<int>> &result)
{
    if(vc.size() == temp.size())
    {
        result.push_back(temp);
        return;
    }
    
    for(int i=0;i<vc.size();i++)
    {
        if(map[i] == false)
        {
            map[i] = true;
            temp.push_back(vc[i]);
            printPermutations(vc,map,temp,result);
            map[i] = false;
            temp.pop_back();
        }
    }
}


int main()
{
    vector<int> vc = {1,2,3};
    vector<bool> map(3,false);
    vector<int> temp;
    vector<vector<int>> result;
    printPermutations(vc,map,temp,result);
    for(auto it : result)
    {
        for(int x : it)
            cout<<x;
        cout<<endl;
    }
    
    
    
}
