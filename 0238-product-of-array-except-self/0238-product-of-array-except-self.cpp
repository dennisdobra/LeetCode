class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int> answer(nums.size(), -1);

        // for (int i = 0; i < nums.size(); i++) {
        //     int product = 1;
        //     for (int j = 0; j < nums.size(); j++) {
        //         if (i != j) {
        //             product *= nums[j];
        //         }
        //     }

        //     answer[i] = product;
        // }

        // return answer;

        vector<int> L(nums.size()), R(nums.size());

        // L[i] contains the product of all the elements to the left
        // Note: for the element at index '0', there are no elements to the
        // left, so the L[0] would be 1
        L[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            // L[i - 1] already contains the product of elements to the left of
            // 'i - 1' Simply multiplying it with nums[i - 1] would give the
            // product of all elements to the left of index 'i'
            L[i] = nums[i - 1] * L[i - 1];
        }

        // R[i] contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to
        // the right, so the R[length - 1] would be 1
        R[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            R[i] = nums[i + 1] * R[i + 1];
        }

        vector<int> answer(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};