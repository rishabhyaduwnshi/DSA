#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    //unordered_set internally uses hash tables. It cannot contain duplicate values
    unordered_set<int> us;
    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    
    //we cannot predict the out for unordered_sets
    for(int x: us)
        cout<<x<<" ";
    cout<<"\n";
    
    //to get size of unordered_set
    cout<<us.size()<<"\n";
    
    //finding an element -> returns an iterator
    if(us.find(15) == us.end())
        cout<<"Not Present\n";
    else
        cout<<"Present\n";
        
    //finding an element using count function -> returns an iterator
    if(us.count(10) == 1)
        cout<<"Present\n";
    else
        cout<<"Not Present\n";
    
    
    //deleting an element
    us.erase(30); //first method
    auto it = us.find(20); //second method
    us.erase(it);
    
    us.erase(us.begin(),us.end());//removes all the elements
        for(int x: us)
        cout<<x<<" ";
    cout<<"\n";
    
    us.clear(); //clears the entire set
}
