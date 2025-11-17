class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());


        while (heap.size() != 1) {
            if (heap.size() == 0) return 0;

            // get the first 2 heaviest stones
            int first = heap.top();
            heap.pop();

            int second = heap.top();
            heap.pop();

            // smash the stones
            if (first == second) continue;

            heap.push(first - second);
        }

        int last = heap.top();
        return last;
    }
};