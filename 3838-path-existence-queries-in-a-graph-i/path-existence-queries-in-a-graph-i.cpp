class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) parent[pa] = pb;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Step 1: connect adjacent nodes
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                unite(i, i - 1);
            }
        }

        // Step 2: answer queries
        vector<bool> ans;
        for (auto &q : queries) {
            if (find(q[0]) == find(q[1]))
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};