class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 1 && citations[0] >= 1) {
            return 1;
        }

        sort(citations.begin(), citations.end(), greater<int>());

        int h = 0, prevH = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) {
                prevH = i + 1;

                if (i == citations.size() - 1) {
                    return prevH;
                }
                
                continue;
            } else {
                h = prevH;
                break;
            }
        }

        return h;
    }
};