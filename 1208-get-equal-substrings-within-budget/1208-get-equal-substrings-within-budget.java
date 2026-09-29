class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int ans = 0;
        int cost = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            cost += Math.abs((s.charAt(right) - 'a') - (t.charAt(right) - 'a'));

            while (cost > maxCost) {
                cost -= Math.abs((s.charAt(left) - 'a') - (t.charAt(left) - 'a'));
                left++;
            }

            ans = Math.max(ans, right - left + 1);
        }

        return ans;
    }
}