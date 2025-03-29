class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        
        int i, j;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                break;
            }
        }

        if (i == 0) {
            j = -1;
        } else {
            j = i - 1;
        }
        
        while (i < nums.size() && j >= 0) {
            if (sq(nums[i]) < sq(nums[j])) {
                result.push_back(sq(nums[i]));
                i++;
            } else {
                result.push_back(sq(nums[j]));
                j--;
            }
        }

        while (i < nums.size()) {
            result.push_back(sq(nums[i]));
            i++;
        }

        while (j >= 0) {
            result.push_back(sq(nums[j]));
            j--;
        }
        
        return result;
    }

    int sq(int x) {
        return x * x;
    }
};