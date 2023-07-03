// solved using dfs to find cycle in graph 
// if there is a cycle in graph the tasks can't be performed
bool dfs( vector<bool> &visited, vector<bool> &path, vector<int> adj[], int node ){
         
    visited[node] = true;
    path[node] = true;

    for(auto it : adj[node]){
        if(!visited[it]){
            if(dfs(visited, path, adj, it)) return true;
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
            if(dfs(visited, path, adj, i)) return true;
        }
    }

    return false;
}

bool isPossible(int v, vector<pair<int, int> >& prerequisites) {
	    
	    int n = prerequisites.size();
	    vector<int> adj[v];
	    for(int i=0; i<n; i++){
	        int p = prerequisites[i].first;
	        int q = prerequisites[i].second;
	        
	        adj[q].push_back(p);
	    }
	    
	    return !isCyclic(v, adj);
}