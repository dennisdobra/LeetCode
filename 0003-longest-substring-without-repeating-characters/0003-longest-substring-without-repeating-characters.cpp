class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> myMap;

        int ans = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            /* check if we found a duplicate */
            if (myMap[s[right]] > 0) {
                /* set left to the index of the first occurence of the current letter */
                left = max(left, myMap[s[right]]);
            }

            ans = max(ans, right - left + 1);
            myMap[s[right]] = right + 1;
        }

        return ans;
    }
};