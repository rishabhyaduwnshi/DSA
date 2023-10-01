bool detect_cycle(vector<int> adjList[], int starting_index, bool visited[])
{
    visited[starting_index] = true;
    queue<pair<int,int>> q;
        
    //current_index, parent
    q.push({starting_index,-1});
        
    while(q.empty() == false)
    {
        int current_node = q.front().first;
        int current_node_parent = q.front().second;
        q.pop();
            
        for(auto it : adjList[current_node])
        {
            if(visited[it] == false)
            {
                visited[it] = true;
                q.push({it,current_node});
            }
            
            else if(current_node_parent != it)
            {
                return true;
            }
        }
    }
    
    return false;
}
    
    
bool isCycle(int V, vector<int> adj[]) 
{
    bool visited[V] = {false};
    for(int i=0;i<V;i++)
    {
        if(visited[i] == false)
        {
            if(detect_cycle(adj,i,visited) == true)
            return true;
        }
    }
    return false;
}
