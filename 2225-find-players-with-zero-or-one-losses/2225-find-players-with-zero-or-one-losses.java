class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
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
}