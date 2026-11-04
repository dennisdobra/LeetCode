class Solution {
    public boolean isPalindrome(String s) {
        s = s.trim();

        int left = 0;
        int right = s.length() - 1;

        while (left <= right) {
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }

            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }

            if (right < left) return false;

            if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
}