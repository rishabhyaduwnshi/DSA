void flood_fill(vector<vector<int>> &image, int sr, int sc, int old_color, int new_color, vector<vector<bool>> &visited)
{
    int n = image.size();
    int m = image[0].size();
        
    if(sr >= 0 && sr < n && sc >= 0 && sc < m)
    { 
        if(visited[sr][sc] == false)
        {
            if(image[sr][sc] == old_color)
            {
                image[sr][sc] = new_color;
                visited[sr][sc] = true;
                    
                //call flood_fill for all possible directions
                flood_fill(image,sr-1,sc,old_color,new_color,visited);
                flood_fill(image,sr+1,sc,old_color,new_color,visited);
                flood_fill(image,sr,sc-1,old_color,new_color,visited);
                flood_fill(image,sr,sc+1,old_color,new_color,visited);
            }
        }   
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) 
{
        
    int n = image.size();
    int m = image[0].size();
    int old_color = image[sr][sc];
    vector<vector<int>> image_copy = image;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
        
    flood_fill(image_copy,sr,sc,old_color,newColor,visited);
    return image_copy;
}
