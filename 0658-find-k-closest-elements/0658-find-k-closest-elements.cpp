class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> heap;

        for (int num : arr) {   // O(N)
            heap.push({abs(num - x), num}); // O(K)


            if (heap.size() > k) {
                heap.pop(); // O(K)
            }
        }

        vector<int> Kclosest;
        while (!heap.empty()) { // O(K)
            auto pair = heap.top(); // O(1)
            heap.pop();             // O(Klog(K))

            Kclosest.push_back(pair.second);
        }

        sort(Kclosest.begin(), Kclosest.end());

        return Kclosest;
    }
};