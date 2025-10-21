class Solution {
public:
    // int subarraySum(vector<int>& nums, int k) {
    //     unordered_map<int, int> prefix_freq{{0, 1}};

    //     int curr = 0;
    //     int num_subarrays = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         curr += nums[i];

    //         num_subarrays += prefix_freq[curr - k];

    //         prefix_freq[curr]++;
    //     }

    //     return num_subarrays;
    // }

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_freq;

        int curr = 0;
        int num_subarrays = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];

            // - ori varianta de sus unde initializez hasmap-ul cu intraream [0 -> 1]
            //   pt a numara toate subarray-urile care incep de la indexul 0
            // - ori mai pun un if unde verific doar subarray-urile care incep de la inceput
            if (curr == k) num_subarrays++;

            num_subarrays += prefix_freq[curr - k];

            prefix_freq[curr]++;
        }

        return num_subarrays;
    }
};