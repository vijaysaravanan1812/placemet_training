
class Solution
{
    void mark_shapes(vector<vector<char>> & grid , int row , int col,
    int x, int y){
        if(x < 0 || y < 0 || x >= row || y >= col
        || grid[x][y] != 'X')
            return;
        
        grid[x][y] = 'Y';
        int dx[] = {1 , -1 , 0 , 0};
        int dy[] = {0 , 0 , -1, 1};
        for(int i = 0 ; i< 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            mark_shapes(grid , row , col , nx , ny );
        } 
        
    }
    
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        
        int number_of_shapes = 0;
        for(int i = 0 ; i< row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 'X')
                {
                    
                    mark_shapes(grid , row , col , i , j);
                    number_of_shapes += 1;
                }
            }
        }
        return number_of_shapes;
        // Code here
    }
};