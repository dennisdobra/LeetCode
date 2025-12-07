class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string newS = "", newT = "";

        for (char c : s) {
            if (!newS.empty() && c == '#') {
                newS.pop_back();
            } else if (c != '#') {
                newS.push_back(c);
            }
        }

        for (char c : t) {
            if (!newT.empty() && c == '#') {
                newT.pop_back();
            } else if (c != '#') {
                newT.push_back(c);
            }
        }

        return newS == newT;
    }
};