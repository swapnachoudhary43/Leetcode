class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<array<int,4>> robots; 
        // {position, health, dir, index}
        for(int i = 0; i < n; i++){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());  // sort by position

        stack<int> st;  // indices of robots vector (only R moving)
        vector<int> finalHealth(n, -1);

        for(int i = 0; i < n; i++){
            int pos = robots[i][0];
            int health = robots[i][1];
            char dir = robots[i][2];
            int idx = robots[i][3];

            if(dir == 'R'){
                st.push(i);
            }
            else{
                // dir == L -> possible collisions
                while(!st.empty() && health > 0){
                    int j = st.top(); // robot moving R
                    int h2 = robots[j][1];

                    if(h2 < health){
                        // R robot dies
                        st.pop();
                        health -= 1;     // L loses 1 health
                        robots[j][1] = 0;
                    }
                    else if(h2 > health){
                        // L robot dies
                        robots[j][1] -= 1; // R loses 1 health
                        health = 0;
                    }
                    else{
                        // equal health -> both die
                        st.pop();
                        robots[j][1] = 0;
                        health = 0;
                    }
                }
                robots[i][1] = health;
            }
        }

        // Collect survivors in original order
        for(auto &r : robots){
            if(r[1] > 0){
                finalHealth[r[3]] = r[1];
            }
        }

        vector<int> ans;
        for(int x : finalHealth){
            if(x != -1) ans.push_back(x);
        }
        return ans;
    }
};