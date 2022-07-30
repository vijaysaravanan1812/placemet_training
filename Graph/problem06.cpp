class Solution
{
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

	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> in_degree(V , 0);
	    vector<bool> visited(V , false);
	    
	    //calculate in in degree
	    for(int u = 0 ; u < V; u++)
	        for(auto x : adj[u])
	            in_degree[x]++;
	 
	    queue<int> q;
	    
	    for(int u = 0 ; u < V ; u++)
	            if(in_degree[u] == 0)
	                q.push(u);
	    
	    int count = 0;
	    vector<int> result;
	    while(!q.empty())
	    {
	        int u = q.front();
	        q.pop();
	        result.push_back(u);
	        
	        for(auto x = adj[u].begin() ; x != adj[u].end() ; x++){
	            if(--in_degree[*x] == 0){
	                q.push(*x);
	            }
	        }
	        count++;
	    }
	    

	   // if(count != V){
	   //     return {};
	   // }
	    return result;
	    
	    
	    
	    
	    
	    // code here
	}
};