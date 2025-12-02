class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixFreq;

        // we don t want to miss a prefix subarray with a sum equal to k
        prefixFreq[0] = 1;  

        int curr = 0;
        int ans = 0;
        for (int num : nums) {
            curr += num;

            if (prefixFreq.contains(curr - k)) {
                ans += prefixFreq[curr - k];
            }

            prefixFreq[curr]++;
        }

        return ans;
    }
};