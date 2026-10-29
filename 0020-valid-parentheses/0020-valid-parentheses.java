class Solution {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        Map<Character, Character> map = new HashMap<>();
        map.put('(', ')');
        map.put('[', ']');
        map.put('{', '}');

        // Map<Character, Character> map = new HashMap<>(Map.of(
        //     '(', ')',
        //     '[', ']',
        //     '{', '}'
        // ));

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty() || map.get(stack.peek()) != c) {
                    return false;
                }

                stack.pop();
            }
        }

        return stack.isEmpty();
    }
}