bool bipartite(vector<int> adj[], int node, vector<int> &color)
{
    queue<int> q;
	    
	q.push(node);
	color[node] = 0;
	    
	while(q.empty() == false)
	{
	    int current_node = q.front();
	    q.pop();
	        
	    for(auto it : adj[current_node])
	    {
	        //if the adjacent node is not colored
	        if(color[it] == -1)
	        {
	            color[it] = !color[current_node];
	            q.push(it);
	        }
	        else if(color[it] == color[current_node])
	            return false;
	    }
	}
	    
    return true;
        
}

bool isBipartite(int V, vector<int>adj[])
{
    vector<int> color(V,-1);
	for(int i=0;i<V;i++)
	{
	    if(color[i] == -1)
	    {
	        if(bipartite(adj,i,color) == false)
	            return false;
	    }
    }
	    
    return true;

}
