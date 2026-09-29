class Solution {
    public String reverseOnlyLetters(String s) {
        char[] arr = s.toCharArray();

        int left = 0;
        int right = arr.length - 1;

        while (left < right) {
            while (left < arr.length && !Character.isAlphabetic(arr[left])) {
                left++;
            }

            while (right >= 0 && !Character.isAlphabetic(arr[right])) {
                right--;
            }

            if (left < right) {
                char aux = arr[left];
                arr[left] = arr[right];
                arr[right] = aux;
            }

            left++;
            right--;
        }

        return new String(arr);
    }
}