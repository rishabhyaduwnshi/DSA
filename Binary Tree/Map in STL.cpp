#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> mp;
    mp.insert({30,1});
    mp.insert({40,2});
    mp.insert({10,3});
    mp.insert({20,4});
    
    for(auto it : mp)
        cout<<it.first<<" "<<it.second<<" \n";
        
    //other functions
    //mp.clear();
    //mp.size();
    //mp.begin();
    //mp.end();
    
    cout<<mp[50]<<" ";
    
}
