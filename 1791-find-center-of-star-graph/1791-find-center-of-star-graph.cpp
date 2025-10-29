class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> freq;

        int star = -1;
        int maxIndegree = -1;
        for (vector<int>& edge: edges) {
            int src = edge[0], dst = edge[1];

            freq[src]++;
            if (freq[src] > maxIndegree) {
                star = src;
                maxIndegree = freq[src];
            }

            freq[dst]++;
            if (freq[dst] > maxIndegree) {
                star = dst;
                maxIndegree = freq[dst];
            }
        }

        return star;
    }
};