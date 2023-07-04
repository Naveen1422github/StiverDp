// tc = v+2e sc = 3v
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


bool isBipartite(int v, vector<int>adj[]){

    vector<int> vis(v, -1);

    for(int i=0; i<v; i++){
        if(vis[i] == -1){
            //if(!bfs(adj, vis, i))return false;
            if(!dfs(adj, vis, i, 0)) return false;
        }
    }

    return true;
	    
}