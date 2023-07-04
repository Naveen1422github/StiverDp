vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        
    vector<bool> visited(v, false);
    visited[0] = true;
    
    queue<int> q;
    q.push(0);

    vector<int> ans;
        
        
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}