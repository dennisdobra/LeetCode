class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_area = 0;
        int left = 0, right = n - 1;

        while (left <= right) {
            int cur_area = min(height[left], height[right]) * (right - left);

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