bool detect_cycle(vector<int> adjList[], vector<bool> &visited, vector<bool> &current_path ,int node)
{
    visited[node] =  true;
    current_path[node] = true;
        
    for(auto it : adjList[node])
    {
            
        if(visited[it] == false)
            if(detect_cycle(adjList,visited,current_path,it) == true)
                return true;
                
        else if(current_path[it] == true)
            return true;
    }
        
    current_path[node] = false;
    return false;
}
    
bool isCyclic(int V, vector<int> adj[]) 
{
    vector<bool> visited(V,false);
    vector<bool> current_path(V,false);
        
    for(int i=0;i<V;i++)
    {
        if(visited[i] == false)
        {
            if(detect_cycle(adj,visited,current_path,i) == true)
                return true;
        }
    }
        
    return false;
}
