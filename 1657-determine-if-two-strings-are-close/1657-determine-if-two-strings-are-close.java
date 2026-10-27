class Solution {
    public boolean closeStrings(String word1, String word2) {
        // edge case
        if (word1.length() != word2.length()) {
            return false;
        }

        // frequency array and distribution map for word1
        int[] freq1 = new int[26];
        Map<Integer, Integer> distro1 = new HashMap<>();

        // frequency array and distribution map for word2
        int[] freq2 = new int[26];
        Map<Integer, Integer> distro2 = new HashMap<>();

        // populate the data structures
        getFreqDistribution(word1, freq1, distro1);
        getFreqDistribution(word2, freq2, distro2);

        // before comparing the distributions we have to check
        // if both words use the exact same letters
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != 0 && freq2[i] == 0 || freq1[i] == 0 && freq2[i] != 0) {
                return false;
            }
        }

        // compare the distribution of the frequencies

        // return distro1.equals(distro2);

        for (var entry : distro1.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();

            if (!distro2.containsKey(key) || distro2.get(key) != value) {
                return false;
            }

            distro2.remove(key);
        }

        // here we should check if distro2 is empty, but considering we checked if both
        // words use the same letters, it implies that at this pot distro2 is empty
        return true;
    }

    public void getFreqDistribution(String word, int[] freq, Map<Integer, Integer> distro) {
        // first we want the frequency of each character
        for (char c : word.toCharArray()) {
            freq[c - 'a']++;
        }

        // now we want the distribution of the frequencies 
        // without caring about the letters involved
        for (int f : freq) {
            if (f != 0) {
                distro.put(f, distro.getOrDefault(f, 0) + 1);
            }
        }
    }
}