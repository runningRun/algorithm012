class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_set<string> visited;
        queue<string> candidate;
        string opt("ACGT");
        int level = 0;
        
        if (bankSet.find(end) == bankSet.end()) {
            return -1;
        }

        // BFS
        candidate.push(start);
        visited.insert(start);
        while (!candidate.empty()) {
            int size = candidate.size();
            level += 1;
            cout << "level: " << level << endl;
            for (int ii = 0; ii < size; ++ii) {
                string oldCandi = candidate.front();
                candidate.pop();
                cout << " " << oldCandi << "==>";
                for (char &ch : oldCandi) {
                    char oldChar = ch;
                    for (char o :  opt) {
                        ch = o;
                        if (oldCandi == end) {
                            cout << "Found " << end << endl;
                            return level;
                        }
                        if (bankSet.find(oldCandi) != bankSet.end() 
                            && visited.find(oldCandi) == visited.end()) {
                            cout << oldCandi << " ";
                            candidate.push(oldCandi);
                            visited.insert(oldCandi);
                        }
                    }
                    ch = oldChar;
                }
                cout << endl;
            }
        }
        return -1;
    }
};