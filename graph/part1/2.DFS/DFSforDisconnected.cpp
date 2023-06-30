void f( vector<bool> &visited , vector<int> adj[], vector<int> &ans, int node){
         
        
    visited[node] = true;
    ans.push_back(node);

    for(auto it : adj[node]){
        if(!visited[it])
        f(visited, adj, ans, it);
    }

}


vector<vector<int>> depthFirstSearch(int v, int E, vector<vector<int>> &edges)
{
       
    vector<int> adj[E];


    for (int i = 0; i < E; i++) {
        int p = edges[i][0]; 
        int q = edges[i][1]; 

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    vector<vector<int>> result;
    
    vector<bool> visited (v+1, false);

    for(int i=0; i<v; i++){

        if(!visited[i]){
            vector<int> ans;
            f(visited, adj, ans, i);
            visited[i] = true;
            result.push_back(ans);
        }
    }

    return result;
       
}