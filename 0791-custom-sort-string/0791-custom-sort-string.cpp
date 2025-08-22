class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> s_chars;

        for (char c : s) {
            s_chars[c]++;
        }

        string result = "";
        for (char c : order) {
            if (s_chars.contains(c)) {
                while (s_chars[c] > 0) {
                    result += c;
                    s_chars[c]--;
                }
                s_chars.erase(c);
            }
        }

        if (s_chars.size() != 0) {
            for (auto& pair : s_chars) {
                while (pair.second > 0) {
                    result += pair.first;
                    pair.second--;
                }
            }
        }

        return result;
    }
};