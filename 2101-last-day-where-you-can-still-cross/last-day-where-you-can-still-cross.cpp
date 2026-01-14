
class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool canCross(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        // Mark flooded cells till "day"
        for(int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }
        
        queue<pair<int,int>> q;
        
        // Start BFS from top row
        for(int c = 0; c < col; c++) {
            if(grid[0][c] == 0) {
                q.push({0, c});
                grid[0][c] = 1; // mark visited
            }
        }
        
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if(r == row - 1) return true; // reached bottom
            
            for(auto &d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return false;
    }
    
    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {
        row = r;
        col = c;
        
        int low = 0, high = cells.size(), ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(canCross(mid, cells)) {
                ans = mid;
                low = mid + 1; // try later day
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
