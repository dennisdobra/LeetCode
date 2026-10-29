class Solution {
    public boolean backspaceCompare(String s, String t) {
        StringBuilder stack1 = new StringBuilder();
        StringBuilder stack2 = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (stack1.length() > 0 && c == '#') {
                stack1.deleteCharAt(stack1.length() - 1);
            } else if (c != '#') {
                stack1.append(c);
            }
        }

        for (char c : t.toCharArray()) {
            if (stack2.length() > 0 && c == '#') {
                stack2.deleteCharAt(stack2.length() - 1);
            } else if (c != '#') {
                stack2.append(c);
            }
        }

        return  stack1.toString().equals(stack2.toString());
    }
}