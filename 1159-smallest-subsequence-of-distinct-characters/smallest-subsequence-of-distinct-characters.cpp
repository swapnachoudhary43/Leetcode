class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
    
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        stack<char> st;
        vector<bool> seen(26, false);

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (seen[c - 'a']) continue;

            while (!st.empty() && 
                   c < st.top() && 
                   last[st.top() - 'a'] > i) {
                
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            seen[c - 'a'] = true;
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};