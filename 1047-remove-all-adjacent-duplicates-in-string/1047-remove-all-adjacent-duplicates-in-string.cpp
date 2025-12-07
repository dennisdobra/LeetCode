class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;

        bool skip = false;
        for (char c : s) {
            while (!stack.empty() && stack.top() == c) {
                stack.pop();
                skip = true;
            }

            if (skip == true) {
                skip = false;
                continue;
            }

            stack.push(c);
        }

        string reversed = "";
        while (!stack.empty()) {
            reversed += stack.top();
            stack.pop();
        }

        reverse(reversed.begin(), reversed.end());

        return reversed;
    }
};