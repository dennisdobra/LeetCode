class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        if (target < letters[0]) {
            return letters[0];
        }

        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;

            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (left == letters.size())  
            return letters[0];  
        else  
            return letters[left];  

    }
};