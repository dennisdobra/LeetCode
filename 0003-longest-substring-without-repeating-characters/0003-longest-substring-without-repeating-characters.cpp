class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashMap;

        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            while (hashMap.contains(s[right])) {
                hashMap[s[left]]--;

                if (hashMap[s[left]] == 0) {
                    hashMap.erase(s[left]);
                }

                left++;
            }

            hashMap[s[right]] = 1;
            
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};