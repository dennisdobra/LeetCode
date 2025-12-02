class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> seen;

        for (int i = 0; i < s.size(); i++) {
            if (seen.contains(s[i])) {
                return s[i];
            }

            seen.insert(s[i]);
        }

        return s[0];
    }
};