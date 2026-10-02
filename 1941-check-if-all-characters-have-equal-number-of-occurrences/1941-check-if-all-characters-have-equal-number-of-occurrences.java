class Solution {
    public boolean areOccurrencesEqual(String s) {
        Map<Character,Integer> freq = new HashMap<>();
        
        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        int frequency = freq.get(s.charAt(0));

        for (var entry : freq.entrySet()) {
            if (frequency != entry.getValue()) {
                return false;
            }
        }

        return true;
    }
}