   
   // tc = o(n) + o(V+2e)  sc = o(n) + o(n)
    void f( vector<bool> &visited , vector<int>adj[], int node){
        
    visited[node] = true;
    for(auto it : adj[node]){
        if(!visited[it]){
        f(visited, adj, it);
        }
    }

    }

  
    int numProvinces(vector<vector<int>> adj, int v) {
        
        //adj matrix to list conversion
        vector<int>adjli[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(adj[i][j]==1 && i!=j){
                    adjli[i].push_back(j);
                    adjli[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited (v, false);
        int result=0; 
        for(int i=0; i<v; i++){
     
        if(!visited[i]){
            f(visited, adjli, i);
            result++;
          }
        }
        return result;
    }
};