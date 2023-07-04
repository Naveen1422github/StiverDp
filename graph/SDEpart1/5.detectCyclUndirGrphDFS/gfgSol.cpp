// sc = n; tc = n=2e + n; 
bool f( vector<bool> &visited , vector<int> adj[], int node, int parent){
         
    visited[node] = true;

    for(auto it : adj[node]){
        if(!visited[it]){
            if(f(visited, adj, it, node)) return true;
        }
        else if(parent != it ) return true;
    }

    return false;

}
    
bool isCycle(int v, vector<int> adj[]) {
    vector<bool> visited (v, false);

    for(int i=0; i<v; i++){

        if(!visited[i]){
            if(f(visited, adj, i, -1)) return true;
            visited[i] = true;
        }
    }

    return false;
}