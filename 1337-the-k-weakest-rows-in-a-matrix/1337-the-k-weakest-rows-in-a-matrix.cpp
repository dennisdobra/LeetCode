class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        vector<pair<int, int>> tmp;

        for (int i = 0; i < mat.size(); i++) {
            tmp.emplace_back(make_pair(FirstCivilian(mat[i]), i));
        }

        sort(tmp.begin(), tmp.end());

        for (int i = 0; i < k; i++) {
            result.emplace_back(tmp[i].second);
        }

        return result;
    }

    int FirstCivilian(vector<int> row) {
        int index = row.size();
        int left = 0, right = row.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (row[mid] == 0) {
                index = mid;
            }

            if (row[mid] > 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return index;
    }
};