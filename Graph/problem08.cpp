class Solution
{
    
    bool DFS(vector<vector<int>> grid , vector<vector<bool>> &visited, int x, int y)
    {
        int row = grid.size();
        int col = grid[0].size();
            
        if(x >= row || x < 0 ||
           y >= col || y < 0 ||
        grid[x][y] == 0 || visited[x][y] == true)
            return false;
            

        if(grid[x][y] == 2)
            return true;
        visited[x][y] = true;
        
        bool d1 = DFS(grid , visited , x , y + 1);
        bool d2 = DFS(grid ,visited , x,   y - 1);
        bool d3 = DFS(grid , visited , x + 1 , y);
        bool d4 = DFS(grid , visited , x - 1 , y);
        
        return d1 || d2 || d3 || d4;
    }
    
    
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row , vector<bool>(col , false));
        
        for(int i = 0 ; i<row ;i++){
            for(int j = 0 ; j< col; j++){
                if(grid[i][j] == 1)
                    return DFS(grid , visited , i ,j);
            }
        }
        return false;
    }
};