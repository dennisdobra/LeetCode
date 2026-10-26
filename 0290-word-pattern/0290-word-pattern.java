class Solution {
    public boolean wordPattern(String pattern, String s) {
        Map<Character, String> map = new HashMap<>();
        Set<String> seen = new HashSet<>();

        String[] words = s.split(" ");
        
        if (words.length != pattern.length()) return false;

        for (int i = 0; i < pattern.length(); i++) {
            char letter = pattern.charAt(i);
            String word = words[i];

            // same letter may not map to different words
            if (map.containsKey(letter) && !map.get(letter).equals(word)) {
                return false;
            }

            // two letters can not map to the same word
            if (!map.containsKey(letter) && seen.contains(word)) {
                return false;
            }

            seen.add(word);
            map.put(letter, word);
        }

        return true;
    }
}