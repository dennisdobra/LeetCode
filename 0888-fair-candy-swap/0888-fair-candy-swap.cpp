class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> result(2);

        int totalAlice = countCandies(aliceSizes);
        int totalBob = countCandies(bobSizes);

        for (int i = 0; i < aliceSizes.size(); i++) {
            for (int j = 0; j < bobSizes.size(); j++) {
                // alice gives bob aliceSizes[i]
                if (aliceSizes[i] == (totalAlice - totalBob) / 2 + bobSizes[j]) {
                    result[0] = aliceSizes[i];
                    result[1] = bobSizes[j];
                    return result;
                }
            }
        }

        return result;
    }

private:
    int countCandies(vector<int> boxes) {
        int result = 0;

        for (int i = 0; i < boxes.size(); i++) {
            result += boxes[i];
        }

        return result;
    }
};
