class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;

        int max_area = 0;

        while (left < right) {
            // calculate the current area
            int curr_area = min(height[left], height[right]) * (right - left);

            max_area = max(max_area, curr_area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};