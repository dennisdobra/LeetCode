class Solution {
public:
    string removeStars(string s) {
        vector<char> stack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                stack.pop_back();
            } else {
                stack.push_back(s[i]);
            }
        }

        string ans = "";
        for (char c : stack) {
            ans += c;
        }

        return ans;
    }
};