class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            prefix = lcp(prefix, strs[i]);
        }

        return prefix;
    }

private:
    string lcp(const string a, const string b) {
        int minSize = 205;
        if (a.size() < b.size()) {
            minSize = a.size();
        } else {
            minSize = b.size();
        }

        int i;
        string lcp = "";
        for (i = 0; i < minSize; i++) {
            if (a[i] == b[i]) {
                lcp += a[i];
            } else {
                break;
            }
        }

        return lcp;
    }
};