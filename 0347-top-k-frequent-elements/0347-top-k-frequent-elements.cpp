class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // first find the frequency of each number
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }

        priority_queue<pair<int, int>> heap;
        
        for (auto& pair : frequency) {
            // -pair.second because we have a max heap => we want the elements with
            // the least frequencies to be at the top
            heap.push({-pair.second, pair.first});

            // important that the pop operation is after we push a new element
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> result;
        while (!heap.empty()) {
            auto curr = heap.top();
            heap.pop();

            result.push_back(curr.second);
        }

        return result;
    }
};