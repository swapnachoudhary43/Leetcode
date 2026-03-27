class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // If stack empty, no matching open bracket
                if (st.empty()) return false;

                char top = st.top();
                st.pop();
                
                // Check for correct matching
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // Stack must be empty in the end
        return st.empty();
    }
};