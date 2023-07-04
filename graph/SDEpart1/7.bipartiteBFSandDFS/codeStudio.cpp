#include<bits/stdc++.h>

bool bfs( vector<int> adj[], vector<int> &vis, int i ){

    queue<int> q;
    q.push(i);
    vis[i] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(vis[it] == -1){
                q.push(it);
                vis[it] = !vis[node];
            }
            else if(vis[it] == vis[node]) return false;
        }
    }
    return true;
}

bool dfs( vector<int> adj[], vector<int> &vis, int node, int flag){

    vis[node] = flag;

    for(auto it:adj[node]){
        if(vis[it] == -1){
            if(!dfs(adj, vis, it, !flag)) return false;
        }
        else if(vis[it] == vis[node]) return false;
    }
    return true;
}



bool isGraphBirpatite(vector<vector<int>> &edges) {

    int n = edges.size();
    int m = edges[0].size();

    vector<int> adj[n];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int v = n;

	vector<int> vis(v, -1);

    for(int i=0; i<v; i++){
        if(vis[i] == -1){
            //if(!bfs(adj, vis, i))return false;
            if(!dfs(adj, vis, i, 0)) return false;
        }
    }

    return true;
}