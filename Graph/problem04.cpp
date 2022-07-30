class Solution {
    void mark_islands(vector<vector<char>> & grid , int x , int y,
    int r , int c){
        if(x < 0 || x >= r || y < 0
        || y >= c || grid[x][y] != '1')
            return ;
        
        grid[x][y] = '2';
        mark_islands(grid , x , y - 1 ,r , c);
        mark_islands(grid , x , y + 1 , r , c);
        mark_islands(grid , x - 1 , y , r , c);
        mark_islands(grid , x + 1 , y , r , c);
        mark_islands(grid , x + 1 , y + 1 , r ,c);
        mark_islands(grid , x - 1 , y - 1 , r ,c);
        mark_islands(grid , x + 1 , y - 1 , r ,c);
        mark_islands(grid , x - 1 , y + 1 , r ,c);
        
        
        
    }
    
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int row = grid.size();
        if(row == 0)
            return -1;

        int col = grid[0].size();
        int number_of_islands = 0;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++ ){
                if(grid[i][j] == '1')
                {
                    mark_islands(grid , i , j , row , col);
                    number_of_islands += 1;
                }
            }
        }
        
        return number_of_islands;
        
    }
};