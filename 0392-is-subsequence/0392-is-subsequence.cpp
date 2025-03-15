class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == "") {
            return true;
        }

        int idx_in_s = 0;

        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[idx_in_s]) {
                idx_in_s++;

                if (idx_in_s == s.size()) {
                    break;
                }
            }
        }

        if (idx_in_s == s.size()) return true;
        return false;
    }
};