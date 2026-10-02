class Solution {
    public int countElements(int[] arr) {
        Map<Integer,Integer> map = new HashMap<>();
        
        for (int num : arr) {
            if (!map.containsKey(num)) {
                map.put(num, 1);
            } else {
                map.put(num, map.get(num) + 1);
            }
        }
        
        int ans = 0;
        for (int num : arr) {
            if (map.containsKey(num + 1)) {
                ans++;
            }
        }
        
        return ans;
    }
}