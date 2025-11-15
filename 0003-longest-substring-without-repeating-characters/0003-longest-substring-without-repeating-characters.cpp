class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars;

        int left = 0, right = 0;

        int res = 0;
        while (right < s.size()) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                // delete the leftmost char
                char l = s[left];
                chars[l]--;
                left++;
            }

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
};