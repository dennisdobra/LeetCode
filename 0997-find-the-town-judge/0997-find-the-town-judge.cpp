class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> trusts;
        unordered_map<int, vector<int>> isTrusted;

        for (vector<int>& relation : trust) {
            int src = relation[0], dst = relation[1];

            trusts[src].push_back(dst);
            isTrusted[dst].push_back(src);
        }

        // find the person who trusts nobody
        int trustsNobody = -1;
        for (int i = 1; i <= n; i++) {
            if (!trusts.contains(i)) {
                trustsNobody = i;
                break;
            }
        }

        if (isTrusted[trustsNobody].size() == n - 1) return trustsNobody;

        return -1;
    }
};