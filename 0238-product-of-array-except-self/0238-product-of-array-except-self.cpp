class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> L(nums.size());
        vector<int> R(nums.size());
        vector<int> answer(nums.size());

        // compute the L vector whre L[i] is the product of all elements to the left
        L[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            L[i] = nums[i - 1] * L[i - 1];
        }

        // compute the R vector where R[i] is the product of all elems to right
        R[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            R[i] = nums[i + 1] * R[i + 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};