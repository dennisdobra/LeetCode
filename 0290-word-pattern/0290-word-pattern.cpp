class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        set<string> seen;

        stringstream ss(s);

        string word;
        int idx = 0;
        while (ss >> word) {
            if (map.contains(pattern[idx]) && map[pattern[idx]] != word) {
                return false;
            }

            if (!map.contains(pattern[idx]) && seen.contains(word)) {
                return false;
            }

            seen.insert(word);
            map[pattern[idx]] = word;
            idx++;
        }

        return idx == pattern.size();
    }
};