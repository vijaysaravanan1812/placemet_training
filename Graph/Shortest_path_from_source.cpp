
#include<bits/stdc++.h>

using namespace std;

vector<int> find_distance(vector<int> adj[], int vertex, int source)
{
    vector<int> distance(vertex   , INT_MAX);
    vector<int> visited(vertex , false);
    queue<int> q ;
    q.push(source);
    visited[source] = true;
    distance[source] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(visited[v] == false){
                distance[v] = distance[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return distance;
}

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
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

// Driver code
int main()
{
	int V = 4;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 1, 3);
    addEdge(adj , 0 , 2);

	printGraph(adj, V);
	
	vector<int> result =  find_distance(adj , V, 0);

	for(int x : result){
		cout<<x<<" ";
	}
	cout<<"\n";
	return 0;
}
