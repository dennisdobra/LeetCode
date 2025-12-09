class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;

        int left = 0;
        int ans = 0;
        
        for (int right = 0; right < s.size(); right++) {
            // add the current character to the window
            map[s[right]]++;

            // make sure the window is valid
            while (map[s[right]] > 1) {
                map[s[left]]--;
                if (map[s[left]] == 0) {
                    map.erase(s[left]);
                }
                left++;
            }

            // windows is valid
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};