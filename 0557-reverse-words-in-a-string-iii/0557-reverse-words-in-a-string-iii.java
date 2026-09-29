class Solution {
    public String reverseWords(String s) {
        char[] arr = s.toCharArray();

        int left = 0;
        while (left < s.length()) {
            int space = s.indexOf(' ', left);
            int right = (space == -1) ? s.length() - 1 : space - 1;

            swapLetters(arr, left, right);

            left = right + 2;
        }

        return new String(arr);
    }

    void swapLetters(char[] arr, int i, int j) {
        while (i < j) {
            char aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;

            i++;
            j--;
        }
    }
}