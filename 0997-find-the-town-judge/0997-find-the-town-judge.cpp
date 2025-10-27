class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdegree(n + 1, 0);
        vector<int> indegree(n + 1, 0);

        for (vector<int>& relation : trust) {
            outdegree[relation[0]]++;
            indegree[relation[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};