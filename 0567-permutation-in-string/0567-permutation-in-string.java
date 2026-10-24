class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length()) return false;

        // set for the characters in s1
        Set<Character> set = new HashSet<>();
        for (char c : s1.toCharArray()) {
            set.add(c);
        }

        // map to track the frequency of each letter in s1
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s1.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // update the map for the first window of length s1.length()
        for (int i = 0; i < s1.length(); i++) {
            char c = s2.charAt(i);

            // it is a letter i do not care about
            if (!set.contains(c)) continue;

            map.put(c, map.getOrDefault(c, 0) - 1);
            if (map.get(c) == 0) {
                map.remove(c);
            }
        }

        if (map.size() == 0) return true;

        for (int i = s1.length(); i < s2.length(); i++) {
            char c = s2.charAt(i);

            // logic for current letter
            if (set.contains(c)) {
                map.put(c, map.getOrDefault(c, 0) - 1);
                if (map.get(c) == 0) {
                    map.remove(c);
                }
            }

            // logic for left bound letter
            char l = s2.charAt(i - s1.length());
            if (set.contains(l)) {
                map.put(l, map.getOrDefault(l, 0) + 1);

                if (map.get(l) == 0) {
                    map.remove(l);
                }
            }

            if (map.size() == 0) return true;
        }

        return false;
    }
}