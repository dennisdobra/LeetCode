class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        map<char,int> Smap, Tmap;

        for (int i = 0; i < s.size(); i++) {
            if (Smap.find(s[i]) == Smap.end()) {
                Smap.insert({s[i], 1});
            } else {
                Smap[s[i]]++;
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (Tmap.find(t[i]) == Tmap.end()) {
                Tmap.insert({t[i], 1});
            } else {
                Tmap[t[i]]++;
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (Smap.find(t[i]) == Smap.end() || Smap[t[i]] != Tmap[t[i]]) {
                return false;
            }
        }

        return true;
    }
};