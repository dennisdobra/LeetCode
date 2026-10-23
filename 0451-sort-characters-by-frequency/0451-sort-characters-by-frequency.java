class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> map = new HashMap<>();

        // track de frequency of each character
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // convert the map into a vector of pairs
        List<Map.Entry<Character, Integer>> list = new ArrayList<>(map.entrySet());

        // List<Map.Entry<Character, Integer>> list = new ArrayList<>();
        // for (var pair : map.entrySet()) {
        //     list.add(pair);
        // }

        // sort the list based on the second element of the pair
        
        // list.sort(Map.Entry.comparingByValue(Comparator.reverseOrder()));

        list.sort(Map.Entry.<Character, Integer>comparingByValue(Comparator.reverseOrder())
            .thenComparing(Map.Entry.comparingByKey()));

        // build the sorted string
        StringBuilder sb = new StringBuilder();
        for (var pair : list) {
            for (int i = 0; i < pair.getValue(); i++) {
                sb.append(pair.getKey());
            }
        }

        return sb.toString();
    }
}