class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;

        int left = 0, right = height.size() - 1;

        while (left <= right) {
            int currArea = min(height[left], height[right]) * (right - left);

            if (currArea > maxArea) {
                maxArea = currArea;
            }

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};