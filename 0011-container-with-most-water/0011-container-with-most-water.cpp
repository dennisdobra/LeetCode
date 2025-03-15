class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0, right = height.size() - 1;

        int cur_area;
        while (left <= right) {
            cur_area = min(height[left], height[right]) * (right - left);

            if (cur_area > max_area) {
                max_area = cur_area;
            }

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};