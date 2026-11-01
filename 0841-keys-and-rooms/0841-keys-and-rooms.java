class Solution {
    Set<Integer> seen = new HashSet<>();

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        // start a dfs from room 0
        seen.add(0);
        dfs(0, rooms);

        return seen.size() == rooms.size();
    }

    public void dfs(int room, List<List<Integer>> rooms) {
        for (int key : rooms.get(room)) {
            if (!seen.contains(key)) {
                seen.add(key);
                dfs(key, rooms);
            }
        }
    }
}