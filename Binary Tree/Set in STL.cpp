#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(30);
    st.insert(40);
    st.insert(10);
    st.insert(20);

    //output of set is always in sorted order in incresing order by default
    for(auto x: st)
        cout<<x<<" ";
        
    cout<<endl;
    
    //decreasing order
    set<int, greater<int>> st_d;
    st_d.insert(30);
    st_d.insert(40);
    st_d.insert(10);
    st_d.insert(20);
    
    for(auto y: st_d)
        cout<<y<<" ";
    
    cout<<endl;
    
    //searching
    if(st.find(20) != st.end())
        cout<<"Found\n";
        
    
    //deleting
    st.erase(20);
    for(auto x: st)
        cout<<x<<" ";
    cout<<endl;
    
    //deletes all the element from set
    st_d.clear();
    cout<<st_d.size()<<"\n";
    
    for(auto it = st.rbegin(); it != st.rend(); it++)
        cout<<*it<<" ";
    
    
    
}
