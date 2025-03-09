class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        sort(deck.begin(), deck.end());

        vector<int> solution(n, 0);

        int idxInDeck = 0;
        int idxInSol = 0;
        bool skip = false;

        while (idxInDeck < n) {
            if (solution[idxInSol] == 0) {
                if (!skip) {
                    solution[idxInSol] = deck[idxInDeck];
                    idxInDeck++;
                }

                skip = !skip;
            }

            idxInSol = (idxInSol + 1) % n;
        }

        return solution;
    }
};
