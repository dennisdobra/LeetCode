class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character,Integer> map = new HashMap<>();

        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            map.put(c, map.getOrDefault(c, 0) + 1);

            while (map.size() > k) {
                char remove = s.charAt(left);
                map.put(remove, map.get(remove) - 1);
                left++;

                if (map.get(remove) == 0) {
                    map.remove(remove);
                }
            }

            ans = Math.max(ans, right - left + 1);
        }

        return ans;
    }
}