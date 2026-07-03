class Solution {
public:
    int n;
    vector<vector<pair<int,long long>>> adj;

    bool can(long long mid, vector<bool>& online, long long k) {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &it : adj[u]) {
                int v = it.first;
                long long cost = it.second;

                // ❌ skip if edge < mid
                if(cost < mid) continue;

                // ❌ skip offline node (except last)
                if(!online[v] && v != n-1) continue;

                if(dist[v] > d + cost) {
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        adj.assign(n, {});

        long long maxEdge = 0;

        // build graph
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            long long c = e[2];
            adj[u].push_back({v, c});
            maxEdge = max(maxEdge, c);
        }

        long long left = 0, right = maxEdge;
        int ans = -1;

        // binary search
        while(left <= right) {
            long long mid = (left + right) / 2;

            if(can(mid, online, k)) {
                ans = mid;
                left = mid + 1; // try bigger
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};