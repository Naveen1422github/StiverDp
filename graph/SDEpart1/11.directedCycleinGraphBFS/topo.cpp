// for a topoSort graph should be DAG that means if we use topoSort
// on a non DAG it will give different results, it gives less element 
// for a node DAG in topoSort list
// that to check directed cylic graph call topsort if sort list have 
// less element that no of nodes that means grpaht is directed cyclic
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

bool isCyclic(int v, vector<int> adj[]) {

    int ans = topoSort(v,adj);

    if(ans==v)return true;

    return false;
}