#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<int> vc[], int starting_point, int ending_point)
{
    vc[starting_point].push_back(ending_point);
    vc[ending_point].push_back(starting_point);
}

void breadthFirstSearch(vector<int> vc[], int starting_point, int node_count)
{
    vector<int> visited(node_count, 0);
    queue<int> q;
    
    q.push(starting_point);
    
    while(!q.empty())
    {
        int visited_node = q.front();
        q.pop();
        
        cout<<visited_node<<" ";
        visited[visited_node] = 1;
       
        for(int x : vc[visited_node])
        {
            if(visited[x] != 1)
            {
                q.push(x);
                visited[x] = 1; // Mark the neighbor as visited
            }
        }
    }
}

int main()
{
    vector<int> vc[4];
    addEdge(vc, 0, 1);
    addEdge(vc, 0, 2);
    addEdge(vc, 1, 2);
    addEdge(vc, 2, 0);
    addEdge(vc, 2, 3);
    addEdge(vc, 3, 3);
    breadthFirstSearch(vc,2,4);
}
