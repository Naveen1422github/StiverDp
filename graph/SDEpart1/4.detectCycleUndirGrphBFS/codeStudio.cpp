#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int v, int m)
{
    vector<bool> visited (v+1, false);

    vector<int> adj[v+1];

    for(int i=0; i<m; i++){
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
        
    queue<pair<int, int>> q;
       
    for(int i=1; i<=v; i++){
        if(!visited[i]){
            q.push({i,-1});
            visited[i] = true;
               
            while(!q.empty()){
            
                int currNode = q.front().first;
                int prevNode = q.front().second; 
            
                q.pop();
             
                for(auto it : adj[currNode]){
                    if(!visited[it]){
                        q.push({it, currNode});
                        visited[it] = true;
                    }
                    else if(it != prevNode){
                        return "Yes";
                    }
                }
            }
        }
    }
    return "No";
}