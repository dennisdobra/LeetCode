class Solution {
public:
    bool isHappy(int n) {
        int prev_result = INT_MIN;
        int curr_result = 0;

        unordered_set<int> seen;

        while (curr_result != 1 || (prev_result != curr_result)) {
            int sum = 0;
            while (n != 0) {
                int last_digit = n % 10;
                sum = sum + (last_digit * last_digit);
                n = n / 10;
            }

            // check for the endless loop
            if (seen.contains(sum)) return false;
            seen.insert(sum);
            
            n = sum;
            curr_result = n;
            prev_result = curr_result;
        }

        if (curr_result == 1) return true;

        return false;
    }
};