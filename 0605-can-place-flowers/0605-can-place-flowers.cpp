class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int canPlace = 0;

        // check the first plot
        if (flowerbed[0] == 0) {
            if (flowerbed.size() == 1 || (flowerbed[1] == 0)) {
                canPlace++;
                flowerbed[0] = 1;
            }
        }

        // check the last plot
        if (flowerbed[flowerbed.size() - 1] == 0) {
            if (flowerbed.size() > 1 && flowerbed[flowerbed.size() - 2] == 0) {
                canPlace++;
                flowerbed[flowerbed.size() - 1] = 1;
            }
        }

        int i;
        for (i = 1; i < flowerbed.size() - 1; i++) {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                canPlace++;
                flowerbed[i] = 1;
                i++;
            }
        }

        if (canPlace >= n) return true;

        return false;
    }
};