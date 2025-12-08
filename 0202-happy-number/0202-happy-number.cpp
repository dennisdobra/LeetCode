class Solution {
public:
    bool isHappy(int n) {
        // use an unordered set to check for infinite loops
        unordered_set<int> seen;

        while (n != 1 && !seen.contains(n)) {
            seen.insert(n);
            n = squareDigits(n);
        }

        return n == 1;
    }

    int squareDigits(int n) {
        int sum = 0;
        while (n != 0) {
            sum += pow(n % 10, 2);
            n = n / 10;
        }

        return sum;
    }
};