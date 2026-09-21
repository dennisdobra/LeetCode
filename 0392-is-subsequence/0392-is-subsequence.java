class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.length() == 0) return true;

        if (t.length() == 0) return false;

        int sIndex = 0;
        int tIndex = 0;

        while (tIndex < t.length() && sIndex < s.length()) {
            if (s.charAt(sIndex) == t.charAt(tIndex)) {
                sIndex++;
            }

            tIndex++;
        }

        return sIndex == s.length();
    }
}