class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0, right = people.size() - 1;

        sort(people.begin(), people.end());

        int boats = 0;
        while(left <= right) {
            int curr_limit = 0;
            int emptySeats = 2;

            while (emptySeats > 0 && right >= 0 && curr_limit + people[right] <= limit) {
                curr_limit += people[right];
                right--;
                emptySeats--;

            }

            while (emptySeats > 0 && left <= people.size() - 1 && curr_limit + people[left] <= limit) {
                curr_limit += people[left];
                left++;
                emptySeats--;
            }

            boats++;
        }

        return boats;
    }
};