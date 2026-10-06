class Solution {
    public int minimumCardPickup(int[] cards) {
        Map<Integer, List<Integer>> map = new HashMap<>();

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < cards.length; i++) {
            // check if we found the same card before
            if (map.containsKey(cards[i])) {
                ans = Math.min(ans, i - map.get(cards[i]).getLast() + 1);
            } else {
                map.put(cards[i], new ArrayList<>());
            }

            map.get(cards[i]).add(i);
        }

        return ans != Integer.MAX_VALUE ? ans : -1;
    }
}