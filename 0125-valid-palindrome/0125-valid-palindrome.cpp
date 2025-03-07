class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'A' and s[i] <= 'Z') {
                s[i] += 32;
            } else if (!isalnum(s[i])) {
                s.erase(i, 1);
                --i;
            }
        }

        int i = 0;
        cout << s;
        if (s.empty())
            return true;

        while (i <= s.size() / 2 ) {
            if (s[i] != s[s.size() - 1 - i])
                return false;
            i++;
        }
        return true;
    }
};