class Solution {
    // Time Complexity: O(n * log(n)) bc of the sort
    // Space Complexity: O(n)
    public int maximumSum_(int[] nums) {
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int num : nums) {
            int key = digitSum(num);

            if (!map.containsKey(key)) {
                map.put(key, new ArrayList<>());
            }

            map.get(key).add(num);
        }

        int ans = Integer.MIN_VALUE;
        for (List<Integer> list : map.values()) {
            Collections.sort(list, Collections.reverseOrder());

            if (list.size() > 1) {
                ans = Math.max(ans, list.get(0) + list.get(1));
            }
        }

        return ans != Integer.MIN_VALUE ? ans : -1;
    }

    // Time Complexity: O(n)
    // Space Complexity: O(n)
    public int maximumSum(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();

        int ans = -1;
        for (int num : nums) {
            int key = digitSum(num);

            if (map.containsKey(key)) {
                ans = Math.max(ans, num + map.get(key));

                map.put(key, Math.max(map.get(key), num));
            } else {
                map.put(key, num);
            }
        }

        return ans;
    }

    public int digitSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
}