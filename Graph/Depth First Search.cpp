#include <bits/stdc++.h>
using namespace std;

int visited[4] = {0};


void addEdge(vector<int> vc[], int starting_point, int ending_point)
{
    vc[starting_point].push_back(ending_point);
    vc[ending_point].push_back(starting_point);
}

void depthFirstSearch(vector<int> vc[], int starting_point, int node_count)
{
        cout<<starting_point<<" ";
        visited[starting_point] = 1;
        
        for(int x: vc[starting_point])
        {
            if(visited[x] != 1)
                depthFirstSearch(vc,x,node_count);
        }
        return;
}

int main()
{
    vector<int> vc[4];
    addEdge(vc,0, 1);
    addEdge(vc,0, 2);
    addEdge(vc,1, 2);
    addEdge(vc,2, 0);
    addEdge(vc,2, 3);
    addEdge(vc,3, 3);
    depthFirstSearch(vc,2,4);
}
