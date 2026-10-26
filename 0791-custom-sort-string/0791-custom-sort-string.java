class Solution {
    public String customSortString(String order, String s) {
        StringBuilder sb = new StringBuilder();

        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        Set<Character> set = new HashSet<>();
        for (char c : order.toCharArray()) {
            set.add(c);
        }

        for (char c : order.toCharArray()) {
            while (map.containsKey(c)) {
                sb.append(c);
                map.put(c, map.get(c) - 1);

                if (map.get(c) == 0) {
                    map.remove(c);
                }
            }
        }

        for (var entry : map.entrySet()) {
            for (int i = 0; i < entry.getValue(); i++) {
                sb.append(entry.getKey());
            }
        }

        return sb.toString();
    }
}