// A simple representation of graph using STL
#include <bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
//	adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v) {
        
        vector<int>::iterator x;
        cout<<v<<" ";
		for (x = adj[v].begin() ; x != adj[v].end() ; ++x)
			cout << "-> " << *x;
		printf("\n");
	}
}

// Driver code
int main()
{
	int V = 8;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 0, 3);
	addEdge(adj, 1, 0);
	addEdge(adj, 1, 4);
	addEdge(adj, 1, 5);
	addEdge(adj, 2, 0);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 0);
    addEdge(adj, 3, 7);
    addEdge(adj, 4, 7);
    addEdge(adj, 4, 1);
    addEdge(adj, 5, 1);
    addEdge(adj, 5, 7);
    addEdge(adj, 6, 2);
    addEdge(adj, 6, 7);
    addEdge(adj, 7, 5);
    addEdge(adj, 7, 6);
    addEdge(adj, 7, 4);
    addEdge(adj, 7, 3);
	printGraph(adj, V);
	return 0;
}
