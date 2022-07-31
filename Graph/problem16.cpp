class Solution {
    
    bool isBipart(int source , vector<int> adj[] , vector<int> &color,
    bool &is_bip){
        queue<int> q;
        color[source] = 1;
        q.push(source);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(find(adj[node].begin() ,adj[node].begin() , node )
             == adj[node].end())
             return false;
            
            for(auto u : adj[node]){
                if(color[u] == -1){
                    color[u] = color[node] ^ 1;
                    q.push(u);
                }
                else 
                is_bip = is_bip & (color[u] != color[node]);
            
            }
            
        }
        return is_bip;
        
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V , -1);
	    bool is_bip = true;
	    for(int i = 0 ; i < V ; i++){
            if(color[i] == -1){

                isBipart(i , adj , color, is_bip);
            }
	    }
	    return  is_bip ;
	}

};