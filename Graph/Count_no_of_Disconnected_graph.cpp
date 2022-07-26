

#include<bits/stdc++.h>


using namespace std;

void bfs(vector<int> adj[] , int s, bool &visited){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto x : adj[u])
        {
            if(visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int count(vector<int> adj[] , int v)
{
    bool visited[v+1];
    int count = 0;
    for(int i = 0 ; i < v ; i++)
        visited[i] = false;
    for(int i = 0 ; i < v ;i++){
        if(visited[i] == false){
            bfs(adj , i , visited);
            count++;
        }
    }
    return count++;
}
