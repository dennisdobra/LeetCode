#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i;
        for (i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());

    }
};