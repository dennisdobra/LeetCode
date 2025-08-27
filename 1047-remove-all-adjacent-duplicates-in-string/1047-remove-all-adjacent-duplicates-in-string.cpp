class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;

        for (char c : s) {
            if (stack.empty()) {
                stack.push(c);
            } else {
                if (c == stack.top()) {
                    stack.pop();
                } else {
                    stack.push(c);
                }
            }
        }

        string result = "";
        while (!stack.empty()) {
            char letter = stack.top();
            result += letter;
            stack.pop();
        }

        // reverse the string
        string ans = "";
        for (int i = result.size() - 1; i >= 0; i--) {
            ans += result[i];
        }

        return ans;
    }
};