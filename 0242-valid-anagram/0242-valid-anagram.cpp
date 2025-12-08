class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mapS;

        for (char c : s) {
            mapS[c]++;
        }

        for (char c : t) {
            if (!mapS.contains(c)) return false;

            mapS[c]--;
            if (mapS[c] == 0) {
                mapS.erase(c);
            }
        }

        return mapS.empty();
    }
};