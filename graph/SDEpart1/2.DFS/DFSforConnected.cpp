#include<bits/stdc++.h>
void f( vector<bool> &visited , vector<int> adj[], vector<int> &ans, int node){
         
        
    visited[node] = true;
    ans.push_back(node);

    for(auto it : adj[node]){
        if(!visited[it])
        f(visited, adj, ans, it);
    }

}
vector<int> dfsOfGraph(int v, vector<int> adj[]) {

    vector<int> ans;
    vector<bool> visited (v, false);
        
    f(visited, adj, ans, 0);

    return ans;
       
}