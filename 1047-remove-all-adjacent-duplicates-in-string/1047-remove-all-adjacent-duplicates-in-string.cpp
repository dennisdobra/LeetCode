class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        stack.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            char curr = s[i];

            if (stack.empty() || (!stack.empty() && curr != stack.top())) {
                stack.push(curr);
                continue;
            }

            while (!stack.empty() && curr == stack.top()) {
                stack.pop();
            }
        }

        string ans = "";
        while(!stack.empty()) {
            char curr = stack.top();
            stack.pop();

            ans += curr;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};