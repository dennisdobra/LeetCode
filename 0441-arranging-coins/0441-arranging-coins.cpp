class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 0) {
            return 0;
        }

        int completeRows = 0;
        int coinsPerRow = 1;
        while (n > 0) {
            n -= coinsPerRow;

            if (n < 0) {
                break;
            }

            coinsPerRow++;
            completeRows++;
        }

        return completeRows;
    }
};
