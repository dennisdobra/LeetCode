class Solution {
    public String removeDuplicates_(String s) {
        Deque<Character> stack = new ArrayDeque<>();

        for (char c : s.toCharArray()) {
            if (stack.isEmpty()) {
                stack.push(c);
                continue;
            }

            if (c == stack.peek()) {
                while (!stack.isEmpty() && c == stack.peek()) {
                    stack.pop();
                }
            } else {
                stack.push(c);
            }
        }

        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }

        sb.reverse();

        return sb.toString();
    }

    public String removeDuplicates(String s) {
        StringBuilder stack = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (stack.length() > 0 && stack.charAt(stack.length() - 1) == c) {
                stack.deleteCharAt(stack.length() - 1);
            } else {
                stack.append(c);
            }
        }

        return stack.toString();
    }
}