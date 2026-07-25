class Solution {
public:
    vector<string> ans;

    void solve(int index, string digits, string &path,
               vector<string> &mapping) {
        
        if (index == digits.size()) {
            ans.push_back(path);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            path.push_back(ch);
            solve(index + 1, digits, path, mapping);
            path.pop_back(); // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        string path = "";
        solve(0, digits, path, mapping);
        return ans;
    }
};