// tc = v+e for making indegree + v for pushing 0 degree in q 
// + v+e for while loop and a for loop inside it
// sc = v for que + v for indegree

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