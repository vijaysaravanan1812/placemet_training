class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        // code here
        int count = 0;
        for(int i = 0 ; i < V ; i++){
            for(auto u : adj[i]){
                count += 1;
            }
        }
        return count;
    }
};