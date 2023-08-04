#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<int> vc[], int starting_point, int ending_point)
{
    vc[starting_point].push_back(ending_point);
    vc[ending_point].push_back(starting_point);
}

void printGraph(vector<int> vc[], int node_count)
{
    for(int i=0; i<node_count; i++)
    {
        cout<<i<<" --> ";
        for(int x : vc[i])
            cout<<x<<" ";
        cout<<endl;
    }
    
}


int main()
{
    vector<int> vc[4];
    addEdge(vc,0,1);
    addEdge(vc,0,2);
    addEdge(vc,1,2);
    addEdge(vc,1,3);
    printGraph(vc,4);
}
