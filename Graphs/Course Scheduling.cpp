//https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& adj) {
        queue<int> q;
        vector<int> indegree(n,0);
        vector<int> g[n];
        
        for(int i=0;i<adj.size();i++){
            int u = adj[i][0];
            int v = adj[i][1];
            g[v].push_back(u);
        }
        
        
        for(int i=0;i<n;i++){
            vector<int>::iterator itr;
            for(itr=g[i].begin();itr!=g[i].end();++itr){
             indegree[*itr]++;   
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
            q.push(i);
            //cout<<indegree[i]<<" ";
        }
        
        //cout<<"\n";
        int count =0;
        cout<<q.size()<<" ";
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            vector<int>::iterator itr;
            
            for(itr=g[u].begin();itr!=g[u].end();itr++){
                if(--indegree[*itr]==0){
                    q.push(*itr);
                }
            }
            
            count++;
        }
        
        //cout<<count<<" ";
        if(count == n)
            return 1;
        return 0;
    }
};
