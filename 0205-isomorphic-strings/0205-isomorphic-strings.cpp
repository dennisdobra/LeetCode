class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;

        unordered_map<char,char> map;
        for (int i = 0; i < s.size(); i++) {
            if (map.contains(s[i])) {
                if (map[s[i]] == t[i]) {
                    continue;
                } else {
                    return false;
                }
            }

            // characters don t have a mapping
            map[s[i]] = t[i];
        }

        return true;
    }
};