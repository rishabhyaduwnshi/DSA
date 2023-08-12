#include <bits/stdc++.h>
using namespace std;

int main()
{
    //by default, this will be max heap, top will always give the max elements
    priority_queue<int> pq;
    
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
