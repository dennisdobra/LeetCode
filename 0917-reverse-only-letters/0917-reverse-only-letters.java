class Solution {
    public String reverseOnlyLetters_(String s) {
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

    public String reverseOnlyLetters__(String s) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (Character.isAlphabetic(c)) {
                stack.add(c);
            }
        }

        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < s.length(); i++) {
            if (Character.isAlphabetic(s.charAt(i))) {
                sb.append(stack.peek());
                stack.pop();
            } else {
                sb.append(s.charAt(i));
            }
        }

        return sb.toString();
    }

    public String reverseOnlyLetters(String s) {
        StringBuilder sb = new StringBuilder();

        int right = s.length() - 1;
        for (int left = 0; left < s.length(); left++) {
            if (Character.isAlphabetic(s.charAt(left))) {
                while (!Character.isAlphabetic(s.charAt(right))) {
                    right--;
                }

                sb.append(s.charAt(right));
                right--;
            } else {
                sb.append(s.charAt(left));
            }
        }

        return sb.toString();
    }
}