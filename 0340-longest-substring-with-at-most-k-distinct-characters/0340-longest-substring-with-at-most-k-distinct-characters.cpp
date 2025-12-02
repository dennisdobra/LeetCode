class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // unordered map to track the frequency of each letter in the substring
        unordered_map<char,int> map;

        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            // add the current letter to the window
            if (!map.contains(s[right])) {
                map[s[right]] = 1;
            } else {
                map[s[right]]++;
            }

            // make sure the window is still valid
            while (map.size() > k) {
                map[s[left]]--;

                if (map[s[left]] == 0) {
                    map.erase(s[left]);
                }

                left++;
            }

            // the window is valid now
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};