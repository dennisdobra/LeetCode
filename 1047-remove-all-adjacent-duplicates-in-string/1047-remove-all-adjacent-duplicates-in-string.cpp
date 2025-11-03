class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        stack.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            char curr = s[i];

            if (!stack.empty() && curr == stack.top()) {
                while (!stack.empty() && curr == stack.top()) {
                    stack.pop();
                }
            } else {
                stack.push(curr);
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