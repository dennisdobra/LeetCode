class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int validIndex = 0;

        int currGain = 0;
        int totalGain = 0;
        for (int i = 0; i < gas.size(); i++) {
            currGain += gas[i] - cost[i];
            totalGain += gas[i] - cost[i];

            if (currGain < 0) {
                // starting the trip from the current validindex with an empty tank
                // if currGain becomes negative it means we can't reach the next
                // gas station => we try to start over from the next gas station
                validIndex = i + 1;
                currGain = 0;   // start with an empty tank
            }
        }

        // no matter at what index we start totalGain has to be >= 0 to
        // be able to perform a full trip
        if (totalGain >= 0) return validIndex;

        return -1;
    }
};