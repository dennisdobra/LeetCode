class Solution {
    public boolean areOccurrencesEqual_(String s) {
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

    // a more efficient implementation with the same complexity
    public boolean areOccurrencesEqual(String s) {
        int[] freq = new int[26];

        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a']++;
        }

        int ref = freq[s.charAt(0) - 'a'];
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0 && freq[i] != ref) {
                return false;
            }
        }

        return true;
    }
}