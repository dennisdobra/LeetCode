class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> result;

        vector<int> visited(transactions.size(), 0);

        for (int i = 0; i < transactions.size() - 1; i++) {
            string curr_transaction = transactions[i];
            vector<string> curr = getData(curr_transaction);

            

            bool currIsValid = true;
            for (int j = i + 1; j < transactions.size(); j++) {
                if (visited[i] != 0 && visited[j] != 0) {
                    continue;
                }

                string next_transaction = transactions[j];
                vector<string> next = getData(next_transaction);
                
                if (validTransactions(curr, next) == false) {
                    currIsValid = false;

                    if (visited[j] == 0) {
                        result.push_back(next_transaction);
                        visited[j] = 1;
                    }
                } else if (stoi(next[2]) > 1000) {
                    if (visited[j] == 0) {
                        result.push_back(next_transaction);
                        visited[j] = 1;
                    }
                }
            }

            // check currIsValid
            if (!currIsValid || stoi(curr[2]) > 1000) {
                if (visited[i] == 0) {
                    result.push_back(curr_transaction);
                    visited[i] = 1;
                }
            }
            
        }

        return result;
    }

    vector<string> getData(string s) {
        string curr = "";
        vector<string> result;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ',') {
                curr += s[i];
            } else {
                result.push_back(curr);
                curr = "";
            }
        }

        result.push_back(curr);

        return result;
    }

    bool validTransactions(vector<string> transaction1, vector<string> transactions2) {
        if (abs(stoi(transactions2[1]) - stoi(transaction1[1])) <= 60 && transaction1[0] == transactions2[0] && transaction1[3] != transactions2[3]) {
            return false;
        }

        return true;
    }
};