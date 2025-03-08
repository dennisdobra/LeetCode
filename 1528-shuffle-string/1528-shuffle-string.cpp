class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string sol = "";

        vector<char> letters(s.size());

        for (int i = 0; i < indices.size(); i++) {
            letters[indices[i]] = s[i];
        }

        for (int i = 0; i < indices.size(); i++) {
            sol += letters[i];
        }

        return sol;
    }
};