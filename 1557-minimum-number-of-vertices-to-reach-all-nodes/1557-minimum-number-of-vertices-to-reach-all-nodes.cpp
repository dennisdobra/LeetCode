class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);

        for (vector<int>& edge : edges) {
            int to = edge[1];
            indegree[to]++;
        }

        vector<int> ans;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};