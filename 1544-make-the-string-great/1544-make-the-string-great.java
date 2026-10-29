class Solution {
    public String makeGood(String s) {
        StringBuilder stack = new StringBuilder();
        
        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() && Math.abs(stack.charAt(stack.length() - 1) - c) == 32) {
                stack.deleteCharAt(stack.length() - 1);
            } else {
                stack.append(c);
            }
        }
        
        return stack.toString();
    }
}