class Solution {
    public boolean closeStrings(String word1, String word2) {
        if (word1.length() != word2.length()) return false;

        int[] freq1 = new int[26];
        int[] freq2 = new int[26];

        Map<Integer, Integer> distro1 = new HashMap<>();
        Map<Integer, Integer> distro2 = new HashMap<>();

        getFrequencies(word1, freq1, distro1);
        getFrequencies(word2, freq2, distro2);

        // check if both words have the exact same letters
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != 0 && freq2[i] == 0 || freq1[i] == 0 && freq2[i] != 0) {
                return false;
            }
        }

        // check if distributions are the same
        for (var entry : distro1.entrySet()) {
            Integer key = entry.getKey();
            Integer value = entry.getValue();

            if (!distro2.containsKey(key) || distro2.get(key) != value) {
                return false;
            }

            distro2.remove(key);
        }

        return true;
    }

    public void getFrequencies(String word, int[] freq, Map<Integer, Integer> distro) {
        for (char c : word.toCharArray()) {
            freq[c - 'a']++;
        }

        for (int f : freq) {
            if (f != 0) {
                distro.put(f, distro.getOrDefault(f, 0) + 1);
            }
        }
    }
}