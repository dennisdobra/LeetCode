class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        // sort(weight.begin(), weight.end()); // O(Nlog(N))

        // int totalWeight = 0;
        // int count = 0;
        // for (int apple : weight) {  // O(N)
        //     if (totalWeight + apple > 5000) {
        //         return count;
        //     }

        //     totalWeight += apple;
        //     count++;
        // }

        // return count;

        // => Time complexity = O(Nlog(N))



        for (int& w : weight) {
            w = -w;
        }

        priority_queue<int> heap(weight.begin(), weight.end()); // O(N)

        int totalWeight = 0;
        int count = 0;

        while (totalWeight < 5000 && !heap.empty()) {
            int curr = -heap.top();     // O(1)
            heap.pop();                 // O(log(N))

            if (totalWeight + curr > 5000) return count;

            totalWeight += curr;
            count++;
        }

        return count;
    }
};