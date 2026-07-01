class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Step 1: Push all thieves
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        // Multi-source BFS
        vector<int> dir = {0,1,0,-1,0};
        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();
            for(int d=0; d<4; d++){
                int nr = r + dir[d];
                int nc = c + dir[d+1];

                if(nr>=0 && nc>=0 && nr<n && nc<n){
                    if(dist[nr][nc] > dist[r][c] + 1){
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        // Step 2: Binary Search
        int low = 0, high = n*n;

        auto can = [&](int val){
            if(dist[0][0] < val) return false;

            queue<pair<int,int>> q;
            vector<vector<int>> vis(n, vector<int>(n,0));
            q.push({0,0});
            vis[0][0] = 1;

            while(!q.empty()){
                auto [r,c] = q.front(); q.pop();
                if(r == n-1 && c == n-1) return true;

                for(int d=0; d<4; d++){
                    int nr = r + dir[d];
                    int nc = c + dir[d+1];

                    if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]){
                        if(dist[nr][nc] >= val){
                            vis[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
            return false;
        };

        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(can(mid)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};