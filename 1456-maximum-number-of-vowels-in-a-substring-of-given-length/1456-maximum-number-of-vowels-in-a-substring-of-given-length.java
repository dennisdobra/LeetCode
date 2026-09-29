class Solution {
    public int maxVowels(String s, int k) {
        int curr = 0;
        int ans = 0;

        // build first window
        for (int i = 0; i < k; i++) {
            if (isVowel(s.charAt(i))) {
                curr++;
            }
        }

        ans = curr;

        for (int i = k; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) curr++;
            if (isVowel(s.charAt(i - k))) curr--;

            ans = Math.max(ans, curr);
        }

        return ans;
    }

    boolean isVowel(char c) {
        return "aeiou".indexOf(c) != -1;
    }
}