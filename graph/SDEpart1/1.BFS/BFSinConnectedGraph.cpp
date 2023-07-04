//solved on gfg
vector<int> bfsOfGraph(int v, vector<int> adj[]) {

    vector<bool> visited(v, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    vector<int> ans;
    ans.push_back(0);
    while(!q.empty()){
            
        int size = q.size();
            
        for(int i=0; i<size; i++){
            int ind = q.front();
            q.pop();
            
            int listSize = adj[ind].size();
                
            for(int i=0; i<listSize; i++){
                int node = adj[ind][i];
                if(!visited[node]){
                    q.push(node);
                    visited[node] = true;
                    ans.push_back(node);
                }
            }
        }
    }
    return ans;
}