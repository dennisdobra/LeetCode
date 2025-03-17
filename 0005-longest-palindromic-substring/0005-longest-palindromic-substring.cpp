class Solution {
public:
    string longestPalindrome(string s) {
        int left, right;
        bool isPalindrome;
        for (int len = s.size(); len > 0; len--) {
            // consider all possible substrings of length 'len'
            for (int start = 0; start <= s.size() - len; start++) {
                // check if the current substring is a palindrome
                left = start;
                right = start + len - 1;
                isPalindrome = true;
                
                while (left < right) {
                    if (s[left] != s[right]) {
                        isPalindrome = false;
                        break;
                    }

                    left++;
                    right--;
                }

                if (isPalindrome) {
                    return s.substr(start, len);
                }
            }
        }

        return "";
    }
};