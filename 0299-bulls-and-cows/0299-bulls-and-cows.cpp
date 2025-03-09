class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> freq(10, 0);

        for (int i = 0; i < secret.size(); i++) {
            freq[secret[i] - '0']++;
        }

        vector<int> vec(10, 0);
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] == secret[i]) {
                continue;
            } else if (guess[i] != secret[i]) {
                vec[secret[i] - '0']++;
            }
        }

        // for (int i = 0; i < vec.size(); i++) {
        //     cout << vec[i] << " ";
        // }

        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else if (vec[guess[i] - '0'] != 0) {
                cows++;
                vec[guess[i] - '0']--;
            }
        }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};