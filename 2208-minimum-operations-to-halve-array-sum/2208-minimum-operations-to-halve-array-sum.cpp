class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> heap(nums.begin(), nums.end());

        double totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int numOperations = 0;
        double halfSum = totalSum / 2;
        while (halfSum > 0) {
            double largest = heap.top();
            heap.pop();

            largest = largest / 2;
            halfSum -= largest;

            heap.push(largest);

            numOperations++;
        }

        return numOperations;
    }
};