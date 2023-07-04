
vector<int> bfs(int v, vector<int> adj[], int src)
{
    vector<bool> visited(v, false);
    queue<pair<int,int>> q;
    vector<int> dis(v, -1);

    q.push({src,0});
    visited[src] = true;
    while(!q.empty()){
     
        int node = q.front().first;
        int wt= q.front().second;
        q.pop();
        dis[node] = wt;
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push({it, wt+1});
            }
        }
    }
    
    return dis;
}

vector<int> shortestPath(vector<vector<int>>& edges, int v,int e, int src){
    vector<int> adj[v];
    for(int i=0; i<e; i++){
        int p = edges[i][0];
        int q = edges[i][1];

        adj[p].push_back(q);
        adj[q].push_back(p);
    } 
    return bfs(v, adj, src);
}