class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        
        queue<tuple<int,int,int>> q;
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;
        
        q.push({0, 0, startHealth});
        visited[0][0] = startHealth;
        
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();
            
            if (r == m-1 && c == n-1) return true;
            
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                
                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    int newHealth = h - grid[nr][nc];
                    
                    if (newHealth > 0 && newHealth > visited[nr][nc]) {
                        visited[nr][nc] = newHealth;
                        q.push({nr, nc, newHealth});
                    }
                }
            }
        }
        
        return false;
    }
};