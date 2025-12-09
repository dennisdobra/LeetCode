class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> counts;

        for (char c : s) {
            if (counts.empty() || counts.back().first != c) {
                counts.push_back({c, 1});
                continue;
            }

            if (++counts.back().second == k) {
                counts.pop_back();
            }
        }

        // build the result
        string res = "";
        for (auto& pair : counts) {
            res += string(pair.second, pair.first);
        }

        return res;
    }
};