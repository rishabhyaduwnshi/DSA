void breadthFirstSearch(vector<int> adjList[], bool visited[], int starting_index)
{
    queue<int> q;
    visited[starting_index] = true;
    q.push(starting_index);
    
    while(q.empty() == false)
    {
        int current_node = q.front();
        q.pop();
            
        for(auto it : adjList[current_node])
        {
            if(visited[it] == false)
            {    
                visited[it] = true;
                q.push(it);
            }
        }
    }
}
    
  
int numProvinces(vector<vector<int>> adj, int V) 
{
    //create adjacency list
    vector<int> adjList[V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(adj[i][j] == 1 && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
        
    //create visited array
    bool visited[V] = {false};
    int count = 0;
        
    //the number of times bfs is called means we have that number of provinces
    for(int i=0;i<V;i++)
    {
        if(visited[i] == false)
        {
            breadthFirstSearch(adjList,visited,i);
            count++;
        }
    }
        
    return count;
}
