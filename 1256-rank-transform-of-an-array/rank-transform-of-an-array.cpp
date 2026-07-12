class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        
        // Step 1: sort
        sort(temp.begin(), temp.end());
        
        // Step 2: assign ranks
        unordered_map<int, int> rank;
        int r = 1;
        
        for (int x : temp) {
            if (rank.find(x) == rank.end()) {
                rank[x] = r++;
            }
        }
        
        // Step 3: build result
        vector<int> result;
        for (int x : arr) {
            result.push_back(rank[x]);
        }
        
        return result;
    }
};