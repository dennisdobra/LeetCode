class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            char[] array = s.toCharArray();
            Arrays.sort(array);

            String sorted = new String(array);

            if (!map.containsKey(sorted)) {
                map.put(sorted, new ArrayList<>());
            }
            map.get(sorted).add(s);

            // map.computeIfAbsent(sorted, k -> new ArrayList<>()).add(s);
        }

        List<List<String>> ans = new ArrayList<>();

        for (List<String> val : map.values()) {
            ans.add(val);
        }

        return ans;
    }
}