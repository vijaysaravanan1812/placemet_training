class Solution 
{
    struct cell{
        int x;
        int y;
        int dis;
        cell(int x , int y , int dis){
            this->x = x;
            this->y = y;
            this->dis = dis;
        }
    };
    
    bool isvalid(int x ,int y ,int N)
    {
        if(x <= 0 || y <= 0 || y > N || x > N){
            return false;
        }
        return true;
    }
    
    
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<bool>> visited(N + 1 , vector<bool> (N + 1 , false));
	    int x ,y ;
	    queue<cell> q;
	    q.push(cell(KnightPos[0] , KnightPos[1], 0));
	    
	    int dx[] = {-2 , -1,  1 , 2, -2, -1, 1, 2 };
	    int dy[] = { -1 , -2 , -2, -1 , 1, 2, 2, 1};
	    
	    visited[KnightPos[0]][KnightPos[1]] = true;
	    
	    
	    while(!q.empty()){
	        cell t = q.front();
	        q.pop();
	        
	        if(t.x == TargetPos[0] && t.y == TargetPos[1] )
	            return t.dis;
	            
	       for(int i = 0 ; i < 8 ; i++)
	       {
	           x = t.x + dx[i];
	           y = t.y + dy[i];
	           
	           if(isvalid(x , y , N) && !visited[x][y]){
	               visited[x][y] = true;
	               q.push(cell(x , y , t.dis + 1));
	           }
	       }
	    }
	    // Code here
	}
};