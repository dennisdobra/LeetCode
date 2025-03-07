class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (!isalnum(s[left]) && left < right) {
                left++;
            }

            while (!isalnum(s[right]) && left < right) {
                right--;
            }

            s[left] = tolower(s[left]);
            s[right] = tolower(s[right]);

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};