class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (char c : s) {
            if (stack.empty()) {
                if (c == '(' || c == '{' || c == '[') {
                    stack.push(c);
                    continue;
                }
                return false;
            }

            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
                continue;
            }

            if (c == ')') {
                if (stack.top() != '(') return false;
            }

            if (c == ']') {
                if (stack.top() != '[') return false;
            }

            if (c == '}') {
                if (stack.top() != '{') return false;
            }

            stack.pop();
        }

        return stack.empty() ? true : false;
    }
};