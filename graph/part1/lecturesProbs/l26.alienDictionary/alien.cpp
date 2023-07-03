// a very good problem i like it 

// when this code is failed?
// when dictionary is given wrong. now how?
// case 1: abcd abc - here correct order should be abc abcd 
// case 2: abc bcd ade  - here you can idetify that case is a cyclic
// so we can add this condition in our code to check for wrong dicionary

// tc = o(v+e) for topo + o(n*l) n is len of dic & l is len of smaller str b/w s1 & s2
// sc = v-indegree + v-q + v-ans + (v+e)-adj
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

string findOrder(string dict[], int n, int v) {

    vector<int> adj[v];
    

    for(int i=0; i<n-1; i++){

        string s1 = dict[i];
        string s2 = dict[i+1];
        
        int l = min(s1.length(), s2.length());

        for(int j=0; j<l; j++){
            if(s1[j]!=s2[j]){
                int p = s1[j] - 'a';
                int q = s2[j] - 'a';
                adj[p].push_back(q);
                break;
            }
        }
 
    }
    
    
    vector<int> order = topoSort(v, adj);
    string ans;
        
    for(int i=0; i<v; i++){
        ans+= char(order[i] + 'a');
    }
    
    return ans;
}

