class Solution
{
    void mark_islands(vector<vector<int>> & grid , int row , int col,
    int x , int y , int &current_area){
        
        if(x < 0 || x >= row || y < 0 || y >= col ||
            grid[x][y] != 1)
            return ;
        
        current_area += 1;
        grid[x][y] = 2;
        int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
        // int dx[] = {-1 , 1 , 0 , 0 , 1 ,1  -1  , -1};
        // int dy[] = {0 , 0 , 1 , -1 , 1 ,-1 , 1 , 1 };
        
        for(int i = 0 ; i < 8 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            mark_islands(grid , row , col , nx , ny , current_area);
            
        }
        
        
        
    }
    
    
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row , vector<bool>(col , false));
        
        int max_area = INT_MIN;
        int current_area = 0;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col; j++){
                if(grid[i][j] == 1){
                    mark_islands(grid , row , col , i , j , current_area);
                   // cout<<"current_area "<<current_area<<"\n";
                    max_area = max(current_area , max_area);
                    current_area = 0;
                }
            }
        }
        
        return max_area;
    }
};