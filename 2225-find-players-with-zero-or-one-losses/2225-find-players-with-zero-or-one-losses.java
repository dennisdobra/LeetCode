class Solution {
    public List<List<Integer>> findWinners_(int[][] matches) {
        // track all players who played at least one match
        Set<Integer> set = new HashSet<>();
        
        List<Integer> players = new ArrayList<>();
        
        // map to track which players lost matches
        Map<Integer,Integer> map = new HashMap<>();
        
        for (int[] match : matches) {
            int winner = match[0];
            int loser = match[1];
            
            if (!set.contains(winner)) {
                players.add(winner);
                set.add(winner);
            }
            
            if (!set.contains(loser)) {
                players.add(loser);
                set.add(loser);
            }
            
            map.put(loser, map.getOrDefault(loser, 0) + 1);
        }
        
        List<Integer> neverLost = new ArrayList<>();
        List<Integer> lostOne = new ArrayList<>();
        
        // players that have not lost any matches = players from seen which do not have an entry in the map
        // players that have lost exactly one match = players from map where the value is one
        
        for (int player : players) {
            if (!map.containsKey(player)) {
                neverLost.add(player);
            }
            
            if (map.containsKey(player) && map.get(player) == 1) {
                lostOne.add(player);
            }
        }
        
        Collections.sort(neverLost);
        Collections.sort(lostOne);
        
        return List.of(neverLost, lostOne);
    }

    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer,Integer> wins = new HashMap<>();   // nr of wins for every player
        Map<Integer,Integer> losses = new HashMap<>(); // nr of losses for every player

        for (int[] match : matches) {
            int winner = match[0];
            int loser = match[1];

            wins.put(winner, wins.getOrDefault(winner, 0) + 1);
            losses.put(loser, losses.getOrDefault(loser, 0) + 1);
        }

        List<Integer> zeroLosses = new ArrayList<>();
        List<Integer> oneLoss = new ArrayList<>();

        for (var pair : wins.entrySet()) {
            if (!losses.containsKey(pair.getKey())) {
                zeroLosses.add(pair.getKey());
            }
        }

        for (var pair : losses.entrySet()) {
            if (losses.get(pair.getKey()) == 1) {
                oneLoss.add(pair.getKey());
            }
        }

        Collections.sort(zeroLosses);
        Collections.sort(oneLoss);

        return List.of(zeroLosses, oneLoss);
    }
}

