class Solution {
    public boolean isIsomorphic(String s, String t) {
        // mappings between characters in s and characters in t
        Map<Character, Character> map = new HashMap<>();

        // set to track chracaters we've seen in t
        Set<Character> set = new HashSet<>();

        for (int i = 0; i < s.length(); i++) {
            char sChar = s.charAt(i);
            char tChar = t.charAt(i);

            // a character may not map to different characters
            if (map.containsKey(sChar) && map.get(sChar) != tChar) {
                return false;
            }

            // No two characters may map to the same character
            if (set.contains(tChar) && !map.containsKey(sChar)) {
                return false;
            }

            set.add(tChar);
            map.put(sChar, tChar);
        }

        return true;
    }
}