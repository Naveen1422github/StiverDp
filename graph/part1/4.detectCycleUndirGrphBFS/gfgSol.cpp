// tc = o(n+2e) sc = o(n)
bool isCycle(int v, vector<int> adj[]) {
    vector<bool> visited (v, false);
        
    queue<pair<int, int>> q;
       
    for(int i=0; i<v; i++){
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
                        return true;
                    }
                }
            }
        }
    }
    return false;
}