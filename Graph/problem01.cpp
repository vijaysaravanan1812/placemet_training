class Solution {
    bool DFSrec(vector<int> adj[] , int source , vector<bool> &visited, vector<bool> &recursion_stack){
        visited[source] = true;
        recursion_stack[source] = true;
        for(auto u : adj[source]){
            if(!visited[u] && DFSrec(adj , u , visited ,recursion_stack))
                return true;
            else if(recursion_stack[u])
                return true;
        }
        recursion_stack[source] = false;
        return false;
    }    
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V + 1 , false);
        vector<bool> recursion_stack(V+1 ,false);
        for(int i = 0 ; i < V; i++){
            if(visited[i] == false)
                if(DFSrec(adj , i , visited , recursion_stack))
                    return true;
        }
        return false;
    }
};