class Solution {
    public String toGoatLatin(String sentence) {
        String[] words = sentence.split(" ");

        Set<Character> vowel = Set.of('A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u');

        StringBuilder sb = new StringBuilder();
        int index = 1;
        for (String word : words) {
            // word begins with vowel
            if (vowel.contains(word.charAt(0))) {
                sb.append(word);
            } else {
                StringBuilder sb2 = new StringBuilder(word);
                sb2.append(word.charAt(0));
                sb2.deleteCharAt(0);
                sb.append(sb2);
            }

            sb.append("ma");
            for (int i = 0; i < index; i++) {
                sb.append('a');
            }

            sb.append(' ');
            index++;
        }

        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }
}