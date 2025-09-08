class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        /* TLE version */
        // vector<int> ans(heights.size(), 0);

        // for (int i = 0; i < heights.size() - 1; i++) {
        //     // for each person 
        //     stack<int> stack;
        //     for (int j = i + 1; j < heights.size(); j++) {
        //         if (stack.empty()) {
        //             stack.push(heights[j]);
        //             if (stack.top() > heights[i]) {
        //                 break;
        //             }

        //             continue;
        //         }

        //         if (!stack.empty() && heights[j] >= stack.top()) {
        //             stack.push(heights[j]);

        //             if (stack.top() > heights[i]) {
        //                 break;
        //             }
        //         }
        //     }

        //     ans[i] = stack.size();
        // }

        // return ans;

        /* Optimal version (linear) */
        stack<int> st;
        vector<int> ans(heights.size(), -1);

        for (int i = heights.size() - 1; i >= 0; i--) {
            int count = 0;

            // shorter people => i can see them
            while (!st.empty() && heights[i] > heights[st.top()]) {
                count++;
                st.pop();
            }

            // this is the first taller one => add one
            if (!st.empty()) {
                count++;
            }

            ans[i] = count;
            st.push(i);
        }

        return ans;
    }
};