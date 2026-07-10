class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
       vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums[a] < nums[b]; });

        vector<int> sortedVal(n), pos(n); 
        for (int i = 0; i < n; i++) {
            sortedVal[i] = nums[idx[i]];
            pos[idx[i]] = i;
        }

        vector<int> far(n);
        int right = 0;
        for (int i = 0; i < n; i++) {
            if (right < i) right = i;
            while (right + 1 < n && sortedVal[right + 1] - sortedVal[i] <= maxDiff) right++;
            far[i] = right;
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        vector<vector<int>> up(LOG + 1, vector<int>(n));
        up[0] = far;
        for (int k = 1; k <= LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];

        vector<int> ans;
        for (auto& q : queries) {
            int u = pos[q[0]], v = pos[q[1]];
            if (u > v) swap(u, v);
            if (u == v) { ans.push_back(0); continue; }

            int cur = u, steps = 0;
            for (int k = LOG; k >= 0; k--) {
                if (up[k][cur] < v) {
                    steps += (1 << k);
                    cur = up[k][cur];
                }
            }
            steps++; 

            if (far[cur] < v) ans.push_back(-1); 
            else ans.push_back(steps);
        }
        return ans;
    }
};