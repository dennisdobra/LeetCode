class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);

        // element -> next greater element
        unordered_map<int,int> map;

        stack<int> stack;

        for (int i = 0; i < nums2.size(); i++) {
            while (!stack.empty() && nums2[i] > stack.top()) {
                // the current element (nums2[i]) is the next greater for stack.top()
                map[stack.top()] = nums2[i];
                stack.pop();
            }

            stack.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (map.contains(nums1[i])) {
                ans[i] = map[nums1[i]];
            }
        }

        return ans;
    }
};