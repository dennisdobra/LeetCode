class Solution {
public:
    int reverse(int x) {
        int inv = 0;
        double tmp = 0;
        while (x != 0) {
            tmp = inv;
            tmp = tmp * 10 + x % 10;
            
            if (tmp >= INT_MAX || tmp < INT_MIN) {
                return  0;
            }

            inv = inv * 10 + x % 10;
            x = x / 10;
        }

        return inv;
    }
};