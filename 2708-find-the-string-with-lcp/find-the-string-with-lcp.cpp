#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n) { p.resize(n); iota(p.begin(), p.end(), 0); }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) p[b] = a;
    }
};

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        DSU dsu(n);

        // Step 1: Union all i, j where lcp[i][j] > 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > 0) {
                    dsu.unite(i, j);
                }
            }
        }

        // Step 2: Assign letters to each group
        vector<int> group(n);
        for (int i = 0; i < n; i++) group[i] = dsu.find(i);

        unordered_map<int, char> mp;
        char nextChar = 'a';

        string ans(n, '?');

        for (int i = 0; i < n; i++) {
            int g = group[i];
            if (!mp.count(g)) {
                if (nextChar > 'z') return "";
                mp[g] = nextChar++;
            }
            ans[i] = mp[g];
        }

        // Step 3: Validate the LCP matrix with the constructed string
        vector<vector<int>> check(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (ans[i] == ans[j]) {
                    if (i == n - 1 || j == n - 1) check[i][j] = 1;
                    else check[i][j] = 1 + check[i + 1][j + 1];
                } else {
                    check[i][j] = 0;
                }
            }
        }

        // If mismatch → return empty string
        if (check != lcp) return "";

        return ans;
    }
};