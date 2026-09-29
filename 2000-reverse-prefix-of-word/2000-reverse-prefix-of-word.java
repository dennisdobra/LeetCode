class Solution {
    public String reversePrefix(String word, char ch) {
        int right = -1;

        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == ch) {
                right = i;
                break;
            }
        }

        if (right == -1) return word;

        char[] arr = word.toCharArray();

        int left = 0;
        while (left < right) {
            char aux = arr[left];
            arr[left] = arr[right];
            arr[right] = aux;

            left++;
            right--;
        }

        return new String(arr);
    }
}