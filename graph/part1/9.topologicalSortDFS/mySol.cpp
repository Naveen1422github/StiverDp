// tc = v+e for dfs + v for push stack data in vec
// sc = 2v for vis and stack + v for ans 
void dfs( vector<int> adj[], vector<bool> &vis, stack<int> &st, int node){

    vis[node] = true;

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(adj, vis, st, it);
        }
    }

    st.push(node);

}

vector<int> topoSort(int v, vector<int> adj[]) 
{
    vector<bool> vis(v, false);

    vector<int> ans;
    stack<int> st;

    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(adj, vis, st, i);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}