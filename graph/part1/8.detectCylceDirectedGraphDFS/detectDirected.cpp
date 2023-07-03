// tc=v+e + v   sc=2n +n


bool f( vector<bool> &visited, vector<bool> &path, vector<int> adj[], int node ){
         
    visited[node] = true;
    path[node] = true;

    for(auto it : adj[node]){
        if(!visited[it]){
            if(f(visited, path, adj, it)) return true;
        }
        else if(path[it]!=0) return true;
    }
    
    path[node] = 0;

    return false;

}
    
bool isCyclic(int v, vector<int> adj[]) {
    vector<bool> visited (v, false);
    vector<bool> path(v,false);

    for(int i=0; i<v; i++){

        if(!visited[i]){
            if(f(visited, path, adj, i)) return true;
        }
    }

    return false;
}