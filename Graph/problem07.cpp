lass Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        if(grid.size() == 0)
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        int total_orange = 0, rotten_orange = 0;
        queue<pair<int , int> > q;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] != 0)
                    total_orange += 1;
                if(grid[i][j] == 2){
                    q.push(make_pair(i , j));
                }
            }
        }
        
        int dx[4] = {1 , -1 , 0 , 0};
        int dy[4] = {0 , 0 , 1 , -1};
        
        int days = 0;
        while(!q.empty()){
            int k = q.size();
            rotten_orange += k;
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i< 4 ; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= row
                    || ny >= col || grid[nx][ny] != 1)
                        continue ;
                    grid[nx][ny] = 2;
                    q.push(make_pair(nx ,ny));
                }
            }
            if(!q.empty())
                days += 1;
            
        }
        
        if(total_orange != rotten_orange)
            return -1;
        return days;
        
        
    }
};