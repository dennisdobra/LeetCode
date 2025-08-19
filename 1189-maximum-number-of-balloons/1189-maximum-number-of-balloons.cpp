class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int instances = 0;
        
        unordered_map<char, int> available;
        unordered_set<char> letters{'b', 'a', 'l', 'o', 'n'};
        
        
        for (int i = 0; i < text.size(); i++) {
            if (letters.find(text[i]) != letters.end()) {
                available[text[i]]++;
            }
        }
        
        while (available.size() == 5) {
            for (auto it = available.begin(); it != available.end(); ) {
                if (it->first == 'l' || it->first == 'o') {
                    it->second -= 2;

                    if (it->second < 0) {
                        return instances;
                    }
                } else {
                    it->second--;
                }

                if (it->second == 0) {
                    it = available.erase(it);
                } else {
                    it++;
                }
            }
            
            instances++;
        }
        
        return instances;
    }
};