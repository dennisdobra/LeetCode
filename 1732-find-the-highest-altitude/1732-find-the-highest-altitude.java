class Solution {
    public int largestAltitude(int[] gain) {
        int total = 0;
        int ans = Integer.MIN_VALUE;
        
        for (int g : gain) {
            total += g;
            ans = Math.max(ans, total);
        }

        return ans >= 0 ? ans : 0;
    }
}