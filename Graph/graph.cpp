// A simple representation of graph using STL
#include <bits/stdc++.h>
using namespace std;

	void DFSrec(vector<int> adj[] , int s , bool visited[] , vector<int> &result)
	{
		result.push_back(s);
		visited[s] = true;
		for(auto u : adj[s]){
			if(visited[u] == false)
				DFSrec(adj , u , visited , result);
		}
	}

	vector<int> DFS(vector<int> adj[] , int v )
	{
		bool visited[v+1];
		vector<int> result;
		for(int i = 0 ; i < v ; i++)
			visited[i] = false;
		for(int i = 0 ; i < v ; i++){
			if(visited[i] == false)
				DFSrec(adj ,  i , visited , result);
		}

		return result;
	}


vector<int> BFS(vector<int> adj[] , int v , int s )
{
	bool visited[v + 1];
	for(int i = 0 ; i < v  ; i++ )
		visited[i] = false;
	queue<int> q;
	visited[s] = true;
	q.push(s);

	vector<int> result;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		result.push_back(u);
		for(int x  : adj[u])
		{
			if(visited[x] == false )
			{
				visited[x] = true;
				q.push(x);
			}
		}
	}
	return result;
}
// A utility function to add an edge in an
// undirected graph.
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
	int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 3, 4);

	printGraph(adj, V);
	
	vector<int> result =  DFS(adj , V  );

	for(int x : result){
		cout<<x<<" ";
	}
	cout<<"\n";
	return 0;
}
