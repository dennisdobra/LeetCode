class Solution {
    public int findLucky(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int num : arr) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        int maxVal = 0;
        for (int key : map.keySet()) {
            if (map.get(key) == key && key > maxVal) {
                maxVal = key;
            }
        }

        return maxVal == 0 ? -1 : maxVal;
    }
}