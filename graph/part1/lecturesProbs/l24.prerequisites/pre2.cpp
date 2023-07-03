    //solved using toposort bfd (kahn's alog)
    vector<int> topoSort(int v, vector<int> adj[]) 
    {
        vector<int> indegree(v,0);

        for(int i=0; i<v; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0; i<v; i++){
            if(indegree[i] == 0)
            q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                q.push(it);
            }
        }

        return ans;
    }
  
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[n];
        
        for(int i=0; i<m; i++){
            int p = prerequisites[i][0];
            int q = prerequisites[i][1];
            
            adj[q].push_back(p);
            
        }
        
        vector<int> ans = topoSort(n, adj); 
        
        if(ans.size()==n) return ans;
        return {};
        
        
    }