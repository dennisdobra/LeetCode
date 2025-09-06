class Solution {
public:
    string predictPartyVictory(string senate) {
        int radiants = 0;
        int dires = 0;

        for (char c : senate) {
            if (c == 'R') {
                radiants++;
            } else {
                dires++;
            }
        }

        int idx = 0;
        int next = -1;
        while (radiants != 0 && dires != 0) {
            if (senate[idx] == 'B') {
                idx = (idx + 1) % senate.size();
                next = -1;
                continue;
            }

            if (senate[idx] == 'R') {
                // find the next closest D
                next = (idx + 1) % senate.size();
                while (senate[next] != 'D') {
                    next = (next + 1) % senate.size();
                }

                dires--;
                senate[next] = 'B';
            } else {
                // find the next closest D
                next = (idx + 1) % senate.size();
                while (senate[next] != 'R') {
                    next = (next + 1) % senate.size();
                }

                radiants--;
                senate[next] = 'B';
            }

            idx = (idx + 1) % senate.size();
        }

        return dires == 0 ? "Radiant" : "Dire";
    }
};