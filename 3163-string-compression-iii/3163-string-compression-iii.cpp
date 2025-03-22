class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        int index = 0;
        int count = 1;
        while (index <= word.size() - 1) {
            if (word[index] == word[index + 1]) {
                count++;

                if (count == 9) {
                    comp += (9 + '0');
                    comp += word[index];
                    count = 1;
                    index++;
                }


            } else {
                comp += (count + '0');
                comp += word[index];
                count = 1;
            }

            index++;
        }

        return comp;
    }
};