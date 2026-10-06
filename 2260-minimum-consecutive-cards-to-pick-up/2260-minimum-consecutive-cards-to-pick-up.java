class Solution {
    public int minimumCardPickup_(int[] cards) {
        Map<Integer, Integer> map = new HashMap<>();

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < cards.length; i++) {
            // check if we found the same card before
            if (map.containsKey(cards[i])) {
                ans = Math.min(ans, i - map.get(cards[i]) + 1);
            }

            map.put(cards[i], i);
        }

        return ans != Integer.MAX_VALUE ? ans : -1;
    }

    public int minimumCardPickup(int[] cards) {
        Map<Integer, Integer> map = new HashMap<>();

        int left = 0;
        int ans = Integer.MAX_VALUE;

        for (int right = 0; right < cards.length; right++) {
            map.put(cards[right], map.getOrDefault(cards[right], 0) + 1);

            while (map.get(cards[right]) == 2) {
                ans = Math.min(ans, right - left + 1);
                
                map.put(cards[left], map.get(cards[left]) - 1);
                left++;
            }
        }

        return ans != Integer.MAX_VALUE ? ans : -1;
    }
}