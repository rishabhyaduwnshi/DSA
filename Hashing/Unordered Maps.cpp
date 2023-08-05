#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string,int> um;
    
    //inserting values
    um["rishabh"] = 1;
    um["yadav"] = 2;
    um.insert({"lucky",3});
    
    //printing all the key value pairs
    for(auto x: um)
        cout<<x.first<<" "<<x.second<<" \n";
        
    
    //finding an element
    if(um.find("rishabh") == um.end())
        cout<<"Not Present\n";
    else
        cout<<"Present\n";
        
    //using count function
    if(um.count("yadav") == 2)
        cout<<"Present";
    else
        cout<<"Not Present\n";
        
    //erasing the elements
    um.erase("rishabh");
    um.erase(um.begin(),um.end());
    um.clear();
    
    
    
}
