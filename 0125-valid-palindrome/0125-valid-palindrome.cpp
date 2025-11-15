class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                str += tolower(s[i]);
            }
        }

        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};