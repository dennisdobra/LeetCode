class Solution {
    // Time Complexity: O(N + M^2), where N is the length of the sentence and
    //                  M is the number of words. The M^2 term comes from the
    //                  suffixes: word i gets i+1 'a' characters, so in total
    //                  1 + 2 + ... + M = M(M+1)/2 = O(M^2) characters.
    // Space Complexity: O(N + M^2) for the words array and the StringBuilder.
    //                   The quadratic part is unavoidable: the output itself
    //                   has that size.
    public String toGoatLatin(String sentence) {
        // N = length of sentence
        // M = number of words

        // O(1) time and space: fixed size of 10 elements
        Set<Character> vowels = Set.of('A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u');

        String[] words = sentence.split(" "); // O(N) time, O(N) space
        StringBuilder sb = new StringBuilder();
        
        int index = 1;

        // the loop runs M times; the cost of each iteration is given below
        for (String word : words) {
            // O(1): hash lookup on a set of 10 elements
            if (vowels.contains(word.charAt(0))) {
                // O(K), K = word length
                sb.append(word);
            } else {
                // substring is O(K), append is O(K)
                sb.append(word.substring(1)).append(word.charAt(0));
            }

            // across all iterations, the appends above cost O(N) in total,
            // since every character of the sentence is copied exactly once

            // O(1)
            sb.append("ma");

            // O(index) for this word; O(M^2) across all iterations
            for (int i = 0; i < index; i++) {
                sb.append("a");
            }
            
            // O(1)
            sb.append(" ");
            index++;
        }

        // O(1): removing the last char
        sb.deleteCharAt(sb.length() - 1);

        // O(N + M^2): copies the whole buffer
        return sb.toString();
    }
}