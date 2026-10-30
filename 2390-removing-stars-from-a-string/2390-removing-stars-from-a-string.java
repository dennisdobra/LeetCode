class Solution {
    public String removeStars_(String s) {
        Deque<Character> stack = new ArrayDeque<>();

        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() && c == '*') {
                stack.pop();
            } else {
                stack.push(c);
            }
        }

        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.peek());
            stack.pop();
        }

        return sb.reverse().toString();
    }

    public String removeStars(String s) {
        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (!sb.isEmpty() && c == '*') {
                sb.deleteCharAt(sb.length() - 1);
            } else {
                sb.append(c);
            }
        }

        return sb.toString();
    }
}