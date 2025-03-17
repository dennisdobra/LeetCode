class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int points = 0;

        int curr_sum = 0;
        for (int i = 0; i < k; i++) {
            curr_sum = curr_sum +  calories[i];
        }

        if (curr_sum < lower) {
            points -= 1;
        } else if (curr_sum > upper) {
            points += 1;
        }

        for (int i = k; i < calories.size(); i++) {
            curr_sum += calories[i];
            curr_sum -= calories[i - k];

            if (curr_sum < lower) {
                points -= 1;
            } else if (curr_sum > upper) {
                points += 1;
            }
        }

        return points;
    }
};