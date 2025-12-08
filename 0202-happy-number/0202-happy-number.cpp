class Solution {
public:
    bool isHappy(int n) {
        // use an unordered set to check for infinite loops
        unordered_set<int> set;

        int sum = 0;
        while (1) {
            sum = squareDigits(n);
            if (sum == 1) return true;

            if (set.contains(sum)) return false;

            set.insert(sum);
            n = sum;
        }

        return false;
    }

    int squareDigits(int n) {
        int sum = 0;

        while (n != 0) {
            sum += pow(n % 10, 2);
            n = n / 10;
        }

        cout << sum << endl;

        return sum;
    }
};