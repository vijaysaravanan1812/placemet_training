class Solution {
  
  void printGraph(vector<int> adj[], int V)
    {
        for (int v = 0; v < V; ++v) {
            
            vector<int>::iterator x;
            cout<<v<<"|";
            for (x = adj[v].begin() ; x != adj[v].end() ; ++x)
                cout << " " << *x;
            printf("\n");
        }
    }

  void BFS(vector<int> adj[], int source , vector<bool>&visited , vector<int> &result){
      list<int> q;
      q.push_back(source);
      visited[source] = true;
      
      while(!q.empty()){
        
        int u = q.front();
        q.pop_front();
        result.push_back(u); 
        
        for(auto x : adj[u]){
            if(visited[x] == false){
                visited[x] = true;
                q.push_back(x);
            
            }
        }
      }
        
      
      
  }
  
  
  public:
    
  
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
      //  printGraph(adj , V);
        vector<bool> visited(V + 1, false);
        vector<int> result;
        
                BFS(adj , 0 , visited , result);
        
        
        return result;
    }
};