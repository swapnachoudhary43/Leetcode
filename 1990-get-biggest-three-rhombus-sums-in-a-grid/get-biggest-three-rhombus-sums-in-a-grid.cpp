class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> st;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                st.insert(grid[i][j]); // size 0 rhombus
                
                for(int k=1; i-k>=0 && i+k<m && j-k>=0 && j+k<n; k++){
                    
                    int sum = 0;
                    
                    int r=i-k, c=j;
                    
                    for(int t=0;t<k;t++) sum+=grid[r+t][c+t];
                    for(int t=0;t<k;t++) sum+=grid[i+t][j+k-t];
                    for(int t=0;t<k;t++) sum+=grid[i+k-t][j-t];
                    for(int t=0;t<k;t++) sum+=grid[i-t][j-k+t];
                    
                    st.insert(sum);
                }
            }
        }
        
        vector<int> ans;
        
        for(auto it = st.rbegin(); it != st.rend() && ans.size()<3; it++)
            ans.push_back(*it);
        
        return ans;
    }
};