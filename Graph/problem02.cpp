Solution {
    
    bool checkForCycle(int source, int parent, vector<int> &visited , vector<int> adj[]) {
      visited[source] = true;
      for (auto u : adj[source]) {
        if (visited[u] == false ) {
          if (checkForCycle(u, source, visited, adj) == true)
            return true;
        } 
        else if (u != parent)
          return true;
      }

      return false;
    }
    

    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector < int > adj[]) {
      vector<int> visited (V + 1, false);
      for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
          if (checkForCycle(i, -1, visited, adj) == true) 
            return true;
        }
      }

      return false;
    }
};