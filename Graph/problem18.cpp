class Solution {
    void flood(vector<vector<int>> & image , vector<vector<bool>> & visited, 
    int x , int y , int row , int col , int newcolor, int cur){
        if(x < 0 || x >= row || y < 0 || y >= col 
        || image[x][y] != cur || visited[x][y] == true )
            return;
        visited[x][y] = true;
        image[x][y] = newcolor;
        int dx[] = {1 , -1, 0 , 0};
        int dy[] ={ 0, 0 , 1 , -1};
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            flood(image , visited , nx ,ny , row , col ,newcolor ,cur );
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int row = image.size();
        int col = image[0].size();
        vector<vector<bool>> visited(row , vector<bool>(col , false));
        
        int cur = image[sr][sc];
        flood(image , visited , sr , sc ,row , col , newColor , cur );
        
        return image;
    }
};