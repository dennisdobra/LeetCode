class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int value = 0;
        for (int i = 0; i < arr1.size(); i++) {
            bool isValid = true;
            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                value++;
            }
        }

        return value;
    }
};