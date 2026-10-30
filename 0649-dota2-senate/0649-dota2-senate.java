class Solution {
    public String predictPartyVictory(String senate) {
        int n = senate.length();

        Queue<Integer> radiant = new ArrayDeque<>();
        Queue<Integer> dire = new ArrayDeque<>();

        // save the indices for the radiants and dires
        for (int i = 0; i < n; i++) {
            if (senate.charAt(i) == 'R') {
                radiant.offer(i);
            } else {
                dire.offer(i);
            }
        }

        while (!radiant.isEmpty() && !dire.isEmpty()) {
            int r = radiant.poll();
            int d = dire.poll();

            // the first one to vote eliminates the other
            // the +n is very important because there are two independent queues
            if (r < d) {
                radiant.offer(r + n);
            } else {
                dire.offer(d + n);
            }
        }

        return radiant.isEmpty() ? "Dire" : "Radiant";
    }
}