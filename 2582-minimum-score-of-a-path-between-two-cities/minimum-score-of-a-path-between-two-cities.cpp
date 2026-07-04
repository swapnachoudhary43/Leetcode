class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        // graph build
        for(auto &r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        
        int ans = INT_MAX;
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            
            for(auto &it : adj[node]){
                int nei = it.first;
                int dist = it.second;
                
                ans = min(ans, dist); // 🔥 key line
                
                if(!visited[nei]){
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }
        
        return ans;
    }
};