class Solution {
public:
    int maximum69Number (int num) {
        // vector<int> digits;

        // while (num != 0) {
        //     digits.push_back(num % 10);
        //     num /= 10;
        // }

        // reverse(digits.begin(), digits.end());

        // bool changed = false;
        // for (int digit : digits) {
        //     if (changed == false && digit == 6) {
        //         digit = 9;
        //         changed = true;
        //     }

        //     num = num * 10 + digit;
        // }

        // return num;

        


        // convert the input 'num' to a string
        string numString = to_string(num);

        // terate over the string from high to low
        for (char& c : numString) {
            if (c == '6') {
                c = '9';
                break;
            }
        }

        return stoi(numString);
    }
};