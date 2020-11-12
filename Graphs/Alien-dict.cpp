vector<char> toposort(vector<int> adj[], int n){
    vector<int> inarr(n,0);
    vector<char> res;
    
    for(int i=0;i<n;i++){
        for(auto j : adj[i]){
            inarr[j]++;
        }
    }
    
    queue<int> q;
    for(int i=0;i<inarr.size();i++){
        if(inarr[i]==0)
            q.push(i);
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        char c = u + 'a';
        res.push_back(c) ;
        for(auto i : adj[u]){
            inarr[i]--;
            if(inarr[i]<=0)
                q.push(i);
        }
    }
    return res;
    
}

string findOrder(string dict[], int n, int k) {
    vector<int> adj[k];
    
    for(int i=0;i<n-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        for(int j = 0; j < min(s1.length(),s2.length()) ; j++){
            if( s1[j]!= s2[j] ){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    vector<char> res;
    res = toposort(adj,k);
    
    string ans;
    for(int i =0;i<res.size();i++){
        ans+= res[i];
    }
    return ans;
    
}
