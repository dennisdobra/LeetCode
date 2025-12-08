class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (string s: strs) {
            prefix = lcp(prefix, s);
        }

        return prefix;
    }

    string lcp(string s, string t) {
        int size = min(s.size(), t.size());

        string lcp = "";
        for (int i = 0; i < size; i++) {
            if (s[i] != t[i]) return lcp;

            lcp += s[i];
        }

        return lcp;
    }
};