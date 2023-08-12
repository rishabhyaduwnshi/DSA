#include <bits/stdc++.h>
using namespace std;

int main()
{
    //min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    
    //pushing the elements
    pq.push(10);
    pq.push(20);
    pq.push(30);
    
    cout<<"Size of queue is : "<<pq.size()<<endl;
    
    cout<<"Elements in queue are : ";
    while(pq.empty() == false)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
