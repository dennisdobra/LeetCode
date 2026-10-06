class Solution {
    public int maximumSum(int[] nums) {
        // group by digitSum

        // sort every List and reverse

        // get the first two

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

    public int digitSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
}