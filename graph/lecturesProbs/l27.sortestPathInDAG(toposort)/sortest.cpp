void dfs( vector<pair<int,int>> adj[], vector<bool> &vis, stack<int> &st, int node){

    vis[node] = true;

    for(auto it:adj[node]){
        if(!vis[it.first]){
            dfs(adj, vis, st, it.first);
        }
    }

    st.push(node);

}

stack<int> topoSort(int v, vector<pair<int,int>> adj[]) 
{
    vector<bool> vis(v, false);

    vector<int> ans;
    stack<int> st;

    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(adj, vis, st, i);
        }
    }
    return st;
}

vector<int> shortestPath(int v,int m, vector<vector<int>>& edges){
    
    vector<pair<int,int>> adj[v];

    for(int i=0; i<m; i++){
        int p = edges[i][0];
        int q = edges[i][1];
        int wt = edges[i][2];
        adj[p].push_back({q,wt});
    }
    stack<int> st = topoSort(v, adj);

    vector<int> dis(v, 1e9);

    dis[0] = 0; 

    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it: adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dis[node] + wt < dis[v]){
                dis[v] = dis[node] + wt;
            }
        }
    }
    
    for (int i = 0; i < v; i++) {
        if (dis[i] == 1e9) dis[i] = -1;
    }
    
    return dis;
}