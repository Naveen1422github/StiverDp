#include <bits/stdc++.h> 



vector<int> BFS(int v, vector<pair<int, int>> edges)
{
    vector<bool> visited(v, false);
   
    queue<int> q;
    
    vector<int> ans;

// making and filling adjacency list
    vector<int> adj[v];
    int size = edges.size();
    for(int i=0; i<size; i++){
        int p = edges[i].first;
        int q = edges[i].second;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }
        
    for(int i=0; i<v; i++){

    if(!visited[i]){
        q.push(i);
        visited[i] = true;
    }
            
    while(!q.empty()){
     
        int node = q.front();
        q.pop();
        ans.push_back(node);
        sort(adj[node].begin(), adj[node].end());
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    
    }
    return ans;
}