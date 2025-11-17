class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(), piles.end());

        // get the toatl number of stones
        int totalStones = 0;
        for (int pile : piles) {
            totalStones += pile;
        }

        for (int i = 0; i < k; i++) {
            int largestPile = heap.top();
            heap.pop();

            int remove = floor(largestPile / 2);
            largestPile -= remove;
            totalStones -= remove;

            heap.push(largestPile);
        }

        int minStones = 0;
        while (!heap.empty()) {
            int largest = heap.top();
            heap.pop();
            minStones += largest;
        }

        return minStones;
    }
};