class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        
        unordered_set<char> characters;
        
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            while (characters.contains(s[right])) {
                characters.erase(s[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
            characters.insert(s[right]);
        }
        
        return ans;
    }
};