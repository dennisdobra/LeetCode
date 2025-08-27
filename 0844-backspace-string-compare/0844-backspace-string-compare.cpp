class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_stack;
        stack<char> t_stack;

        string s1 = typeString(s);
        string s2 = typeString(t);

        return s1 == s2;
    }

    string typeString(string str) {
        string ans = "";

        for (char c : str) {
            if (ans.empty() && c == '#') continue;

            if (c != '#') {
                ans += c;
            } else {
                ans.pop_back();
            }
        }

        return ans;
    }
};