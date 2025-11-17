class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        int distinct = freq.size();
        priority_queue<int> heap;

        // push every frequency onto a min heap
        for (auto& p : freq) {
            heap.push(-p.second);
        }

        while (k != 0) {
            int curr = heap.top();
            heap.pop();

            // can no longer decrease the number of distinct elements
            if (-curr > k) return distinct;

            k += curr; // + because curr is negative
            distinct--;
        }

        return distinct;
    }
};