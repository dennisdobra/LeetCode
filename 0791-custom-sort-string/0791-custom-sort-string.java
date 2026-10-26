class Solution {
    public String customSortString_(String order, String s) {
        StringBuilder sb = new StringBuilder();

        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
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

    public String customSortString(String order, String s) {
        StringBuilder sb = new StringBuilder();
        int[] chars = new int[26];

        // O(s.length())
        for (char c : s.toCharArray()) {
            chars[c - 'a']++;
        }

        // O(order.length()) + O(s.length())
        for (char c : order.toCharArray()) {
            // if all characters from s are also found in order,
            // this while loop iterates s.length() times in total
            while (chars[c - 'a'] > 0) {
                sb.append(c);
                chars[c - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            while (chars[i] > 0) {
                sb.append((char)('a' + i));
                chars[i]--;
            }
        }

        return sb.toString();
    }
}