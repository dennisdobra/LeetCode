class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;

        int idx = 0;
        for (int num : pushed) {
            stack.push(num);

            while (!stack.empty() && stack.top() == popped[idx]) {
                stack.pop();
                idx++;
            }
        }

        return idx == pushed.size();
    }
};